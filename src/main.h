#pragma once
#define TURN_CAPACITY 10
enum color { none, white, black };
typedef struct cells {
    enum { empty, pawn, rook, knight, bishop, queen, king } figure;
    enum color colorOfTheFigure;
} cell;
struct Board {
    cell thisCell[8][8];
    char turn[TURN_CAPACITY];
    enum color queue;
};