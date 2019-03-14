#include "board.h"
#include <stdio.h>
int makeaTurn(char turn[10], int color, char (*board)[8][8]) {
    int parsedTurn = turnParse(turn);
    if (parsedTurn < 6 || checkLogic(turn, parsedTurn, color, *board)) {
        return 1;
    }

    switch (parsedTurn) {
    case 6:
        (*board)[7 - (turn[4] - 49)][turn[3] - 97] =
            (*board)[7 - (turn[1] - 49)][turn[0] - 97];
        (*board)[7 - (turn[1] - 49)][turn[0] - 97] = ' ';
        break;
    case 7:
        (*board)[7 - (turn[5] - 49)][turn[4] - 97] =
            (*board)[7 - (turn[2] - 49)][turn[1] - 97];
        (*board)[7 - (turn[2] - 49)][turn[1] - 97] = ' ';
        break;
    }
    return 0;
}

int turnParse(char turn[10]) {
    int checkOnFigure = ((turn[0] == 82) || (turn[0] == 78) ||
                         (turn[0] == 66) || (turn[0] == 81) || (turn[0] == 75))
                            ? 1
                            : 0;
    int checkOnTurnStart = checkOnFigure == 0
                               ? ((turn[0] > 96 && turn[0] < 105) &&
                                  (turn[1] > 48 && turn[1] < 58))
                                     ? 2
                                     : 0
                               : ((turn[1] > 96 && turn[1] < 105) &&
                                  (turn[2] > 48 && turn[2] < 58))
                                     ? 2
                                     : 0;
    int checkOnTurn = checkOnFigure == 0
                          ? turn[2] == 45 || turn[2] == 120 ? 2 : 0
                          : turn[3] == 45 || turn[3] == 120 ? 2 : 0;
    int checkOnTurnEnd = checkOnFigure == 0
                             ? ((turn[3] > 96 && turn[3] < 105) &&
                                (turn[4] > 48 && turn[4] < 58))
                                   ? 2
                                   : 0
                             : ((turn[4] > 96 && turn[4] < 105) &&
                                (turn[5] > 48 && turn[5] < 58))
                                   ? 2
                                   : 0;
    printf("%d %d %d %d \n", checkOnFigure, checkOnTurnStart, checkOnTurn,
           checkOnTurnEnd);
    return checkOnFigure + checkOnTurnStart + checkOnTurn + checkOnTurnEnd;
}

int checkLogic(char turn[10], int parsedTurn, int color, char board[8][8]) {
    switch (parsedTurn) {
    case 6:
        if (board[7 - (turn[1] - 49)][turn[0] - 97] != 32 &&
            board[7 - (turn[1] - 49)][turn[0] - 97] != 80 &&
            board[7 - (turn[1] - 49)][turn[0] - 97] != 112) {
            return 1;
        }

        if (turn[2] == 45 && board[7 - (turn[4] - 49)][turn[3] - 97] != 32) {
            return 1;
        }

        if (turn[2] == 120 && board[7 - (turn[4] - 49)][turn[3] - 97] == 32) {
            return 1;
        }

        break;
    case 7:
        if (board[7 - (turn[2] - 49)][turn[1] - 97] != turn[0] &&
            (int)board[7 - (turn[2] - 49)][turn[1] - 97] != turn[0] + 32) {
            return 1;
        }

        if (turn[3] == 45 && board[7 - (turn[5] - 49)][turn[4] - 97] != 32) {
            return 1;
        }

        if (turn[3] == 120 && board[7 - (turn[5] - 49)][turn[4] - 97] == 32) {
            return 1;
        }
        break;
    }
    return 0;
}