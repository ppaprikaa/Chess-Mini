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

bitboard bitboard_pawn_attack_mask(unsigned long long square, int side) {
	bitboard attacks = 0ULL;
	bitboard piece = 0ULL;	
	PUT_BIT(piece, square);

	if (side == 0) {
		if((piece >> 7) & bitboard_not_a_file) 
			attacks |= (piece >> 7);
		if((piece >> 9) & bitboard_not_h_file)
			attacks |= (piece >> 9);
	} else {
		if((piece << 7) & bitboard_not_h_file) 
			attacks |= (piece << 7);
		if((piece << 9) & bitboard_not_a_file)
			attacks |= (piece << 9);
	}

	return attacks;
}

bitboard bitboard_knight_attack_mask(unsigned long long square) {
	bitboard attacks = 0ULL;
	bitboard piece = 0ULL;	
	PUT_BIT(piece, square);

	if((piece >> 17) & bitboard_not_h_file) 
		attacks |= (piece >> 17);
	if((piece >> 15) & bitboard_not_a_file)
		attacks |= (piece >> 15);
	if((piece >> 10) & bitboard_not_gh_file)
		attacks |= (piece >> 10);
	if((piece >> 6) & bitboard_not_ab_file) 
		attacks |= (piece >> 6);

	if((piece << 17) & bitboard_not_a_file) 
		attacks |= (piece << 17);
	if((piece << 15) & bitboard_not_h_file)
		attacks |= (piece << 15);
	if((piece << 10) & bitboard_not_ab_file)
		attacks |= (piece << 10);
	if((piece << 6) & bitboard_not_gh_file) 
		attacks |= (piece << 6);

	return attacks;
}
