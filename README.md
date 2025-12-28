# OCR using Tesseract

## Dependencies
- [Tesseract](https://github.com/tesseract-ocr/tesseract)
- [Tesseract Language Trained Data](https://github.com/tesseract-ocr/tessdata)
- [Leptonica](https://github.com/DanBloomberg/leptonica)

## Usage
`./ocr IMAGE_FILE` will output the detected text onto STDOUT

## Note: Language Data packs
Tesseract requires language data packs. The relevant data pack (`.traineddata`
file) for the language must be present in `/usr/share/tessdata/` directory.

For eg., to detect english text (default), the `eng.traineddata` file must be
present in the above mentioned directory.

If installing language data file to system directory is not possible, the env
variable `TESSDATA_PREFIX` can also be used.

For eg., if `eng.traineddata` file is in the current directory, the following
command can be used to use it.

`TESSDATA_PREFIX=$(pwd) ./ocr IMAGE_FILE`

