#pragma once
#include "typedef.h"
#include "chess_constants.h"

void bitboard_print(bitboard board);

bitboard bitboard_pawn_attack_mask(unsigned long long square, int side);
