#include "board.h"
#include <stdio.h>
int makeaTurn(char turn[10], int color, char board[8][8]) {
    int parsedTurn = turnParse(turn);
    if (parsedTurn < 3) {
        return -1;
    }
    return 1;
}

int turnParse(char turn[10]) {
    int checkOnFigure = ((turn[0] == 82) || (turn[0] == 78) ||
                         (turn[0] == 66) || (turn[0] == 81) || (turn[0] == 75))
                            ? 1
                            : 0;
    int checkOnTurnStart =
        checkOnFigure == 0
            ? ((turn[0] > 96 && turn[0] < 105) && (turn[1] > 0 && turn[1] < 9))
                  ? 1
                  : 0
            : ((turn[1] > 96 && turn[1] < 105) && (turn[2] > 0 && turn[2] < 9))
                  ? 1
                  : 0;
    int checkOnTurn = checkOnFigure == 0
                          ? turn[2] == 45 || turn[2] == 120 ? 1 : 0
                          : turn[3] == 45 || turn[3] == 120 ? 1 : 0;
    int checkOnTurnEnd =
        checkOnFigure == 0
            ? ((turn[3] > 96 && turn[3] < 105) && (turn[4] > 0 && turn[4] < 9))
                  ? 1
                  : 0
            : ((turn[4] > 96 && turn[4] < 105) && (turn[5] > 0 && turn[5] < 9))
                  ? 1
                  : 0;
    return checkOnFigure + checkOnTurnStart + checkOnTurn + checkOnTurnEnd;
}