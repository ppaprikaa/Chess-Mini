SOURCE_FILES=main.c bitboard.c

build:
	clang -o main -Wall -Werror $(SOURCE_FILES)
