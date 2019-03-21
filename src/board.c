#include "board.h"
#include "main.h"
#include <stdio.h>
int makeaTurn(int color) {
    int FigureToMakeATurn = 0;
    int parsedTurn = turnParse(&FigureToMakeATurn);

    int startingCellNumber = 7 - turn[1] + 49;
    int startingCellLetter = turn[0] - 97;
    int endingCellNumber = 7 - turn[4] + 49;
    int endingCellLetter = turn[3] - 97;
    if (parsedTurn < 6 ||
        checkLogic(color, FigureToMakeATurn, startingCellNumber,
                   startingCellLetter, endingCellNumber, endingCellLetter)) {
        return 1;
    }

    board[endingCellNumber][endingCellLetter] =
        board[startingCellNumber][startingCellLetter];
    board[startingCellNumber][startingCellLetter].figure = empty;
    board[startingCellNumber][startingCellLetter].color = none;

    return 0;
}

int turnParse(int *FigureToMakeATurn) {
    int checkOnFigure =
        (turn[0] == 'R')
            ? 2
            : (turn[0] == 'N')
                  ? 3
                  : (turn[0] == 'B')
                        ? 4
                        : (turn[0] == 'Q')
                              ? 5
                              : (turn[0] == 'K')
                                    ? 6
                                    : (turn[0] > 96 && turn[0] < 105) ? 1 : -1;
    if (checkOnFigure > 0) {
        *FigureToMakeATurn = checkOnFigure;
    }
    if (checkOnFigure > 1) {
        for (int i = 0; i < TURN_CAPACITY - 1; ++i) {
            turn[i] = turn[i + 1];
        }
    }

    // check whether the entered value of the turn start is correct
    int checkOnTurnStart =
        ((turn[0] > 96 && turn[0] < 105) && (turn[1] > 48 && turn[1] < 58)) ? 2
                                                                            : 0;

    // check whether the entered value of the turn action is correct
    int checkOnTurn = turn[2] == '-' || turn[2] == 'x' ? 2 : 0;

    // check whether the entered value of the turn end is correct
    int checkOnTurnEnd =
        ((turn[3] > 96 && turn[3] < 105) && (turn[4] > 48 && turn[4] < 58)) ? 2
                                                                            : 0;
    return checkOnFigure + checkOnTurnStart + checkOnTurn + checkOnTurnEnd;
}

int checkLogic(int color, int FigureToMakeATurn, int startingCellNumber,
               int startingCellLetter, int endingCellNumber,
               int endingCellLetter) {

    // check if there is a figure on the starting cell
    if (board[startingCellNumber][startingCellLetter].figure == empty ||
        board[startingCellNumber][startingCellLetter].figure !=
            FigureToMakeATurn) {
        return 1;
    }

    // check whether ending cell is empty
    if (turn[2] == '-' &&
        board[endingCellNumber][endingCellLetter].figure != empty) {
        return 1;
    }

    // check if there is a figure on the ending cell
    if (turn[2] == 'x' &&
        board[endingCellNumber][endingCellLetter].figure == empty) {
        return 1;
    }

    return 0;
}