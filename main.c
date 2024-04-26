#include <stdio.h>
#include <stdlib.h>
#include "bitboard.h"

int main(int argc, char* argv[argc + 1]) {
	for (size_t r = 0; r < 8; r++) {
	
		for (size_t f = 0; f < 8; f++) {
			bitboard_print(bitboard_bishop_attack_mask(r * 8 + f));
		}
	}

	return EXIT_SUCCESS;
}
