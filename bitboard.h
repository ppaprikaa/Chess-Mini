#pragma once
#include <stddef.h>

#include "typedef.h"
#include "chess_constants.h"

void bitboard_print(bitboard board);

bitboard bitboard_pawn_attack_mask(bitboard square, int side);
bitboard bitboard_knight_attack_mask(bitboard square);
bitboard bitboard_king_attack_mask(bitboard square);

// note: these are return relevant occupancy bits so file a and h and rank 1 and 8 will not have bits set to 1
bitboard bitboard_bishop_attack_mask(bitboard square);
bitboard bitboard_rook_attack_mask(bitboard square);

bitboard bitboard_bishop_attack_mask_blocked(bitboard square, bitboard block);
bitboard bitboard_rook_attack_mask_blocked(bitboard square, bitboard block);

// TODO: bitboard_set_occupancy
bitboard bitboard_set_occupancy(bitboard index, size_t attack_mask_bitcount, bitboard attack_mask);

// counts bitcount
size_t bitboard_bitcount(bitboard board);

//returns -1 if bitboard is zero, otherwise index of least significant bit
int bitboard_find_lsb_index(bitboard board);

