# OCR using Tesseract

## Dependencies
- [Tesseract](https://github.com/tesseract-ocr/tesseract)
- [Tesseract Language Trained Data](https://github.com/tesseract-ocr/tessdata)
- [Leptonica](https://github.com/DanBloomberg/leptonica)

Tesseract requires language data packs. The relevant data pack (`.traineddata`
file) for the language must be present in `/usr/share/tessdata/` directory.

For eg., to detect english text (default), the `eng.traineddata` file must be
present in the above mentioned directory.

## Usage
`./ocr IMAGE_FILE` will output the detected text onto STDOUT
