#include <stdio.h>
#include <stdlib.h>
#include "bitboard.h"

int main(int argc, char* argv[argc + 1]) {
	for (int rank = 0; rank < 8; rank++) {
		for (int file = 0; file < 8; file++) {
			bitboard_print(bitboard_rook_attack_mask(rank * 8 + file));
		}
	}

	return EXIT_SUCCESS;
}
