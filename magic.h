#pragma once
#include "typedef.h"

// generate pseudo random unsigned int
unsigned int uint_random();

// generates magic number candidate
bitboard generate_magic_number();

// find_magic from https://www.chessprogramming.org/Looking_for_Magics
bitboard find_magic_number(int square, int relevant_bits, int is_bishop);
