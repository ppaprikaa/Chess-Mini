#include "magic.h"

unsigned int rand = 1681692777;

unsigned int uint_random() {
	unsigned int num = rand;	

	num ^= num << 13;	
	num ^= num << 13;
	num ^= num << 13;	
	
	rand = num;
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
