SOURCE_FILES=main.c bitboard.c chess_constants.c magic.c

build:
	clang -o main -Wall -Werror $(SOURCE_FILES)

build-verbose:
	clang -o main -Wall -Werror -v $(SOURCE_FILES)
