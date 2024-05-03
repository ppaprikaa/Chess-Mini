#include "magic.h"
#include "bitboard.h"

#include <string.h>
#include <stdio.h>

unsigned int seed = 1804289383;

unsigned int uint_random() {
	unsigned int num = seed;	

	num ^= num << 13;	
	num ^= num >> 17;
	num ^= num << 5;	
	
	seed = num;
	return num;
}

// generates random bitboard
bitboard generate_random_bitboard() {
	bitboard b1, b2, b3, b4;

	// for each random preserve first 16 bits removing others
	b1 = (bitboard)(uint_random() & 0xFFFF);
	b2 = (bitboard)(uint_random() & 0xFFFF);
	b3 = (bitboard)(uint_random() & 0xFFFF);
	b4 = (bitboard)(uint_random() & 0xFFFF);

	// bitwise or and shift by n * 16 each 16 bit long random so that it would fit into 64bit bitboard
	return b1 | (b2 << 16) | (b3 << 32) | (b4 << 48);
}

// generates magic number candidate
bitboard generate_magic_number() {
	return generate_random_bitboard() & generate_random_bitboard() & generate_random_bitboard();
}

// * square - represents initial square
// * relevant bits - get from look up table for bishop or rook
// on chess programming wiki people used bitcount method instead, but I do not care
// * sliding_piece - piece enum of sliding pieces may be found in chess constants header
bitboard find_magic_number(int square, int relevant_bits, int sliding_piece) {
	bitboard occupancies[4096], attacks[4096], used[4096];
	
	// attack mask
	bitboard attack_mask = sliding_piece == bishop  ? bitboard_bishop_attack_mask(square) : bitboard_rook_attack_mask(square);

	int occupancy_indices = 1 << relevant_bits;
	for (int i = 0; i < occupancy_indices; i++)	 {
		occupancies[i] = bitboard_set_occupancy(i, relevant_bits, attack_mask);
		attacks[i] = sliding_piece == bishop ?
			bitboard_bishop_attack_mask_blocked(square, occupancies[i]) :
			bitboard_rook_attack_mask_blocked(square, occupancies[i]);
	}
	
	int try = 0;
	for (try = 0; try < 100000000; try++) {
		bitboard magic_number = generate_magic_number();

		if(bitboard_bitcount((attack_mask * magic_number) & 0xFF00000000000000) < 6) { continue; }

		memset(used, 0ULL, sizeof(used));

		int fail = 0;

		int i = 0;
		for (i = 0, fail = 0; !fail && (i < occupancy_indices); i++) {
			int magic_index = (int)((occupancies[i] * magic_number) >> (64 - relevant_bits));

			if(used[magic_index] == 0ULL)
				used[magic_index] = attacks[i];
			else if (used[magic_index] != attacks[i])
				fail = 1;
		}

		if (!fail)
			return magic_number;
	}
	printf("%d\n", try);
	printf("magic number failed\n");
	return 0ULL;
}
