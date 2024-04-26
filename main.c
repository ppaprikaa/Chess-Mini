#include <stdio.h>
#include <stdlib.h>
#include "bitboard.h"

int main(int argc, char* argv[argc + 1]) {
	for(size_t rank = 0; rank < 8; rank++) {
		for (size_t file = 0; file < 8; file++) {
			size_t square = rank * 8 + file;
			bitboard king_attack = bitboard_king_attack_mask(square);
			bitboard_print(king_attack);
			if (king_attack != king_attacks[square]) {
				exit(1);
			}
		}
	}
	return EXIT_SUCCESS;
}
