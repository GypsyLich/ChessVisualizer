#pragma once
#include "main.h"
int makeaTurn(struct Board *board);
int checkLogic(struct Board *board, int figureToMakeATurn,
               int startingCellNumber, int startingCellLetter,
               int endingCellNumber, int endingCellLetter);
int turnParse(struct Board *board, int *figureToMakeATurn);
int checkStartingCell(int startingCell, int figureToMakeATurn);
int checkResultingCellForMove(int resultingCell, char turn);
int passTurnStart(char turn[TURN_CAPACITY]);
int passTurnMove(char turn[TURN_CAPACITY]);
int passTurnEnd(char turn[TURN_CAPACITY]);
int passFigure(char turn[TURN_CAPACITY]);