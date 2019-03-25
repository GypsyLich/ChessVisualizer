#include "board.h"
#include <stdio.h>
int makeaTurn(struct Board *board) {
    int FigureToMakeATurn = 0;
    int parsedTurn = turnParse(board, &FigureToMakeATurn);

    int startingCellNumber = 7 - board->turn[1] + 49;
    int startingCellLetter = board->turn[0] - 97;
    int endingCellNumber = 7 - board->turn[4] + 49;
    int endingCellLetter = board->turn[3] - 97;
    if (parsedTurn < 6 ||
        checkLogic(board, FigureToMakeATurn, startingCellNumber,
                   startingCellLetter, endingCellNumber, endingCellLetter)) {
        return 1;
    }

    board->thisCell[endingCellNumber][endingCellLetter] =
        board->thisCell[startingCellNumber][startingCellLetter];
    board->thisCell[startingCellNumber][startingCellLetter].figure = empty;
    board->thisCell[startingCellNumber][startingCellLetter].colorOfTheFigure =
        none;

    return 0;
}

int turnParse(struct Board *board, int *FigureToMakeATurn) {
    int checkOnFigure;
    switch (board->turn[0]) {
    case 'R':
        checkOnFigure = 2;
        break;
    case 'N':
        checkOnFigure = 3;
        break;
    case 'B':
        checkOnFigure = 4;
        break;
    case 'Q':
        checkOnFigure = 5;
        break;
    case 'K':
        checkOnFigure = 6;
        break;
    default:
        checkOnFigure = (board->turn[0] > 96 && board->turn[0] < 105) ? 1 : -1;
        break;
    }
    if (checkOnFigure > 0) {
        *FigureToMakeATurn = checkOnFigure;
    }
    if (checkOnFigure > 1) {
        for (int i = 0; i < TURN_CAPACITY - 1; ++i) {
            board->turn[i] = board->turn[i + 1];
        }
    }

    // check whether the entered value of the turn start is correct
    int checkOnTurnStart = ((board->turn[0] > 96 && board->turn[0] < 105) &&
                            (board->turn[1] > 48 && board->turn[1] < 58))
                               ? 2
                               : 0;

    // check whether the entered value of the turn action is correct
    int checkOnTurn = board->turn[2] == '-' || board->turn[2] == 'x' ? 2 : 0;

    // check whether the entered value of the turn end is correct
    int checkOnTurnEnd = ((board->turn[3] > 96 && board->turn[3] < 105) &&
                          (board->turn[4] > 48 && board->turn[4] < 58))
                             ? 2
                             : 0;
    return checkOnFigure + checkOnTurnStart + checkOnTurn + checkOnTurnEnd;
}

int checkLogic(struct Board *board, int FigureToMakeATurn,
               int startingCellNumber, int startingCellLetter,
               int endingCellNumber, int endingCellLetter) {
    // check if there is a figure on the starting cell
    if (board->thisCell[startingCellNumber][startingCellLetter].figure ==
            empty ||
        board->thisCell[startingCellNumber][startingCellLetter].figure !=
            FigureToMakeATurn) {
        return 1;
    }

    // check whether ending cell is empty
    if (board->turn[2] == '-' &&
        board->thisCell[endingCellNumber][endingCellLetter].figure != empty) {
        return 1;
    }

    // check if there is a figure on the ending cell
    if (board->turn[2] == 'x' &&
        board->thisCell[endingCellNumber][endingCellLetter].figure == empty) {
        return 1;
    }

    return 0;
}