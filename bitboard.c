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

bitboard bitboard_pawn_attack_mask(bitboard square, int side) {
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

bitboard bitboard_knight_attack_mask(bitboard square) {
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

bitboard bitboard_king_attack_mask(bitboard square) {
	bitboard attacks = 0ULL;
	bitboard piece = 0ULL;	
	PUT_BIT(piece, square);

	if (piece >> 8) attacks |= piece >> 8;
	if (piece << 8) attacks |= piece << 8;

	if ((piece >> 9) & bitboard_not_h_file) attacks |= piece >> 9;
	if ((piece >> 7) & bitboard_not_a_file) attacks |= piece >> 7;
	if ((piece << 9) & bitboard_not_a_file) attacks |= piece << 9;
	if ((piece << 7) & bitboard_not_h_file) attacks |= piece << 7;
	
	if ((piece >> 1) & bitboard_not_h_file) attacks |= piece >> 1;
	if ((piece << 1) & bitboard_not_a_file) attacks |= piece << 1;

	return attacks;
}

bitboard bitboard_bishop_attack_mask(bitboard square) {
	bitboard attacks = 0ULL;

	int r, f;
	int pr = square / 8, pf = square % 8;

	for (r = pr + 1, f = pf + 1; r <= 6 && f <= 6; r++, f++) PUT_BIT(attacks, (r * 8 + f));
	for (r = pr - 1, f = pf - 1; r >= 1 && f >= 1; r--, f--) PUT_BIT(attacks, (r * 8 + f));
	for (r = pr + 1, f = pf - 1; r <= 6 && f >= 1; r++, f--) PUT_BIT(attacks, (r * 8 + f));
	for (r = pr - 1, f = pf + 1; r >= 1 && f <= 6; r--, f++) PUT_BIT(attacks, (r * 8 + f));

	return attacks;
}

bitboard bitboard_rook_attack_mask(bitboard square) {
	bitboard attacks = 0ULL;

	int r, f;
	int pr = square / 8, pf = square % 8;

	f = pf;
	for (r = pr + 1; r <= 6; r++) PUT_BIT(attacks, (r * 8 + f));
	for (r = pr - 1; r >= 1; r--) PUT_BIT(attacks, (r * 8 + f));
	r = pr;
	for (f = pf + 1; f <= 6; f++) PUT_BIT(attacks, (r * 8 + f));
	for (f = pf - 1; f >= 1; f--) PUT_BIT(attacks, (r * 8 + f));

	return attacks;
}

bitboard bitboard_bishop_attack_mask_blocked(bitboard square, bitboard block) {
	bitboard attacks = 0ULL;

	int r, f;
	int pr = square / 8, pf = square % 8;

	for (r = pr + 1, f = pf + 1; r <= 7 && f <= 7; r++, f++) {
		PUT_BIT(attacks, (r * 8 + f));
		if ((1ULL << (r * 8 + f)) & block) break;
	}
	for (r = pr - 1, f = pf - 1; r >= 0 && f >= 0; r--, f--) {
		PUT_BIT(attacks, (r * 8 + f));
		if ((1ULL << (r * 8 + f)) & block) break;
	}
	for (r = pr + 1, f = pf - 1; r <= 7 && f >= 0; r++, f--) {
		PUT_BIT(attacks, (r * 8 + f));
		if ((1ULL << (r * 8 + f)) & block) break;
	}
	for (r = pr - 1, f = pf + 1; r >= 0 && f <= 7; r--, f++) {
		PUT_BIT(attacks, (r * 8 + f));
		if ((1ULL << (r * 8 + f)) & block) break;
	}
	

	return attacks;
}

bitboard bitboard_rook_attack_mask_blocked(bitboard square, bitboard block) {
	bitboard attacks = 0ULL;

	int r, f;
	int pr = square / 8, pf = square % 8;

	f = pf;
	for (r = pr + 1; r <= 7; r++) { 
		PUT_BIT(attacks, (r * 8 + f));
		if ((1ULL << (r * 8 + f)) & block) break;
	}
	for (r = pr - 1; r >= 0; r--) {
		PUT_BIT(attacks, (r * 8 + f));
		if ((1ULL << (r * 8 + f)) & block) break;
	}
	r = pr;
	for (f = pf + 1; f <= 7; f++) {
		PUT_BIT(attacks, (r * 8 + f));
		if ((1ULL << (r * 8 + f)) & block) break;
	}
	for (f = pf - 1; f >= 0; f--) { 
		PUT_BIT(attacks, (r * 8 + f));
		if ((1ULL << (r * 8 + f)) & block) break;
	}

	return attacks;
}

bitboard bitboard_set_occupancy(bitboard index, size_t attack_mask_bitcount, bitboard attack_mask) {
	bitboard occupancy = 0ULL;
	
	for (size_t i = 0; i < attack_mask_bitcount; i++) {
		int lsb = bitboard_find_lsb_index(attack_mask);
		POP_BIT(attack_mask, lsb);
		if (index & (1 << i)) {
			occupancy |= (1ULL << lsb);
		}
	}

	return occupancy;
}

size_t bitboard_bitcount(bitboard board) {
	size_t count = 0;
	while(board) { board &= board - 1; count++; }
	return count;
}

int bitboard_find_lsb_index(bitboard board) {
	if (board) {
		return bitboard_bitcount((board & -board) - 1);
	}

	return -1;
}
