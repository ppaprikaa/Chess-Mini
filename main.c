#include "bitboard.h"
#include "bit_gears.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[argc + 1]) {
	bitboard board = 1ULL | 2ULL;

	PUT_BIT(board, a8);
	PUT_BIT(board, b8);
	bitboard_print(board);
	getchar();

	POP_BIT(board, b8);
	bitboard_print(board);
	getchar();

	POP_BIT(board, b8);
	bitboard_print(board);
	getchar();

	return EXIT_SUCCESS;
}
