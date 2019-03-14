#ifndef __BOARD_H__
#define __BOARD_H__
int makeaTurn(char turn[10], int color, char (*board)[8][8]);
int checkLogic(char turn[10], int parsedTurn, int color, char board[8][8]);
int turnParse(char turn[10]);
#endif