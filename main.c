#include <stdlib.h>
#include <stdio.h>
#include "bitboard.h"
#include "bit_gears.h"

int main(int argc, char* argv[argc + 1]) {
	bitboard board = 1ULL | 2ULL;

	PUT_BIT(board, a8);
	PUT_BIT(board, b8);
	bitboard_print(board);
	getchar();

	POP_BIT(board, b8);
	bitboard_print(board);
	getchar();

	bitboard pawn_attacks_mask = bitboard_pawn_attack_mask(e2, white);
	bitboard_print(pawn_attacks_mask);

	return EXIT_SUCCESS;
}
