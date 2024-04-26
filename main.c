#include <stdio.h>
#include <stdlib.h>
#include "bitboard.h"

int main(int argc, char* argv[argc + 1]) {
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			bitboard square = i * 8 + j;
			bitboard knight_attacks_mask = bitboard_knight_attack_mask(square);
			bitboard_print(knight_attacks_mask);
			if (knight_attacks_mask != knight_attacks[square]) {
				exit(1);
			}
		}
	}

	return EXIT_SUCCESS;
}
