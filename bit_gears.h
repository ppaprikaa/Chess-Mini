#pragma once

#define GET_BIT(board, square) (board & (1ULL << square))
#define PUT_BIT(board, square) (board |= (1ULL << square))
#define POP_BIT(board, square) (board &= ~(1ULL << square))
