#pragma once
#include "typedef.h"

// sides to move
enum {
	white, black
};

// not_<file> - bitboard with all bits set to 1 except <file> bits
extern const bitboard bitboard_not_a_file;
extern const bitboard bitboard_not_h_file;
extern const bitboard bitboard_not_b_file;
extern const bitboard bitboard_not_g_file;
extern const bitboard bitboard_not_gh_file;
extern const bitboard bitboard_not_ab_file;

// pawn attacks table
extern const bitboard pawn_attacks[2][64];
extern const bitboard knight_attacks[64];
extern const int bishop_attack_bits_bitcount[64];
extern const int rook_attack_bits_bitcount[64];
extern const bitboard king_attacks[64];

// sliding pieces
enum {
	rook, bishop
};

// squares
// ! in bitboards order !
enum {
	a8,b8,c8,d8,e8,f8,g8,h8,
	a7,b7,c7,d7,e7,f7,g7,h7,
	a6,b6,c6,d6,e6,f6,g6,h6,
	a5,b5,c5,d5,e5,f5,g5,h5,
	a4,b4,c4,d4,e4,f4,g4,h4,
	a3,b3,c3,d3,e3,f3,g3,h3,
	a2,b2,c2,d2,e2,f2,g2,h2,
	a1,b1,c1,d1,e1,f1,g1,h1,
};

// index to chess coordinate table
extern const char coordinates[64][3]; /* = {
	"a8","b8","c8","d8","e8","f8","g8","h8",
	"a7","b7","c7","d7","e7","f7","g7","h7",
	"a6","b6","c6","d6","e6","f6","g6","h6",
	"a5","b5","c5","d5","e5","f5","g5","h5",
	"a4","b4","c4","d4","e4","f4","g4","h4",
	"a3","b3","c3","d3","e3","f3","g3","h3",
	"a2","b2","c2","d2","e2","f2","g2","h2",
	"a1","b1","c1","d1","e1","f1","g1","h1",
}; */
