#include "board.h"
#include <stdio.h>
int makeaTurn(struct Board *board) {
    int figureToMakeATurn = 0;
    int parsedTurn = turnParse(board, &figureToMakeATurn);

    int startingCellNumber = 7 - board->turn[1] + 49;
    int startingCellLetter = board->turn[0] - 97;
    int endingCellNumber = 7 - board->turn[4] + 49;
    int endingCellLetter = board->turn[3] - 97;
    if (parsedTurn < 6 ||
        checkLogic(board, figureToMakeATurn, startingCellNumber,
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

int turnParse(struct Board *board, int *figureToMakeATurn) {
    int figureFlag = passFigure(board->turn);
    /*switch (board->turn[0]) {
    case 'R':
        passFigure = 2;
        break;
    case 'N':
        passFigure = 3;
        break;
    case 'B':
        passFigure = 4;
        break;
    case 'Q':
        passFigure = 5;
        break;
    case 'K':
        passFigure = 6;
        break;
    default:
        passFigure = (board->turn[0] > 96 && board->turn[0] < 105) ? 1 : -1;
        break;
    }
    if (passFigure > 0) {
        *figureToMakeATurn = passFigure;
    }
    if (passFigure > 1) {
        for (int i = 0; i < TURN_CAPACITY - 1; ++i) {
            board->turn[i] = board->turn[i + 1];
        }
    }

    // check whether the entered value of the turn start is correct
    int passTurnStart = ((board->turn[0] > 96 && board->turn[0] < 105) &&
                            (board->turn[1] > 48 && board->turn[1] < 58))
                               ? 2
                               : 0;

    // check whether the entered value of the turn action is correct
    int passTurnMove = board->turn[2] == '-' || board->turn[2] == 'x' ? 2 :
    0;

    // check whether the entered value of the turn end is correct
    int passTurnEnd = ((board->turn[3] > 96 && board->turn[3] < 105) &&
                          (board->turn[4] > 48 && board->turn[4] < 58))
                             ? 2
                             : 0;*/

    if (figureFlag > 0) {
        *figureToMakeATurn = figureFlag;
    }
    if (figureFlag > 1) {
        for (int i = 0; i < TURN_CAPACITY - 1; ++i) {
            board->turn[i] = board->turn[i + 1];
        }
    }
    return figureFlag + passTurnStart(board->turn) + passTurnMove(board->turn) +
           passTurnEnd(board->turn);
}

int checkLogic(struct Board *board, int figureToMakeATurn,
               int startingCellNumber, int startingCellLetter,
               int endingCellNumber, int endingCellLetter) {
    if (checkStartingCell(
            board->thisCell[startingCellNumber][startingCellLetter].figure,
            figureToMakeATurn)) {
        printf("There is no such figure on the starting cell\n");
        return 1;
    }
    if (checkResultingCellForMove(
            board->thisCell[endingCellNumber][endingCellLetter].figure,
            board->turn[2])) {
        printf("Incorrect move: trying to capture the figure on empty cell or "
               "make a move on occupied cell\n");
        return 1;
    }
    return 0;
}

//     MISC FUNCTIONS
int checkStartingCell(int startingCell, int figureToMakeATurn) {
    if (startingCell == empty || startingCell != figureToMakeATurn) {
        return 1;
    }
    return 0;
}

int checkResultingCellForMove(int resultingCell, char turn) {
    if (turn == '-' && resultingCell != empty) {
        return 1;
    }
    if (turn == 'x' && resultingCell == empty) {
        return 1;
    }
    return 0;
}

int passFigure(char turn[TURN_CAPACITY]) {
    int passFigure;
    switch (turn[0]) {
    case 'R':
        passFigure = 2;
        break;
    case 'N':
        passFigure = 3;
        break;
    case 'B':
        passFigure = 4;
        break;
    case 'Q':
        passFigure = 5;
        break;
    case 'K':
        passFigure = 6;
        break;
    default:
        passFigure = (turn[0] > 96 && turn[0] < 105) ? 1 : -1;
        break;
    }
    return passFigure;
}

int passTurnStart(char turn[TURN_CAPACITY]) {
    if ((turn[0] > 96 && turn[0] < 105) && (turn[1] > 48 && turn[1] < 58)) {
        return 2;
    } else {
        return 0;
    }
}

int passTurnMove(char turn[TURN_CAPACITY]) {
    if (turn[2] == '-' || turn[2] == 'x') {
        return 2;
    } else {
        return 0;
    }
}

int passTurnEnd(char turn[TURN_CAPACITY]) {
    if ((turn[3] > 96 && turn[3] < 105) && (turn[4] > 48 && turn[4] < 58)) {
        return 2;
    } else {
        return 0;
    }
}