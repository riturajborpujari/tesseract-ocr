LIBS=lept tesseract
ocr: main.c
	gcc \
		-Wall -Wextra \
		$$(pkg-config --cflags $(LIBS)) \
		-o ocr \
		main.c \
		$$(pkg-config --libs $(LIBS))
