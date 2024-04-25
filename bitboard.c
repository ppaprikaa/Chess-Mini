#include "bitboard.h"
#include "bit_gears.h"
#include <stdio.h>

void bitboard_print(bitboard board) {
	for (size_t r = 0; r < 8; r++) {
		printf("%zu  ", 8 - r);
		for(size_t f = 0; f < 8; f++) {
			size_t square_index = r * 8 + f;
			printf("%d ", GET_BIT(board, square_index) ? 1 : 0);
		}
		printf("\n");
	}

	printf("   a b c d e f g h\n");
	printf("\n\n   Bitboard: %llu\n", board);
}
