#pragma once
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
