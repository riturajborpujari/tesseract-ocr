#include <stdio.h>
#include <allheaders.h>
#include <tesseract/capi.h>

void die(const char *errstr)
{
	fprintf(stderr, errstr);
	exit(1);
}

int main(int argc, char *argv[])
{
	if (argc < 2) die("Invalid Usage\n");

	PIX *img            = 0;
	char *text          = 0;
	TessBaseAPI *handle = 0;

	if((img = pixRead(argv[1])) == NULL) die("Error reading image\n");

	handle = TessBaseAPICreate();
	if(TessBaseAPIInit2(handle, NULL, "eng", OEM_LSTM_ONLY) != 0) die("Error initializing tesseract\n");

	TessBaseAPISetImage2(handle, img);
	if(TessBaseAPIRecognize(handle, NULL) != 0) die("Error in Tesseract recognition\n");

	if((text = TessBaseAPIGetUTF8Text(handle)) == NULL) die("Error getting text\n");

	fprintf(stdout, text);

	TessDeleteText(text);
	TessBaseAPIEnd(handle);
	TessBaseAPIDelete(handle);
	pixDestroy(&img);

	return 0;
}
