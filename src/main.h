#pragma once
#define TURN_CAPACITY 10
typedef struct cells {
    enum { empty, pawn, rook, knight, bishop, queen, king } figure;
    enum { none, white, black } color;
} cell;
cell board[8][8];
char turn[TURN_CAPACITY];