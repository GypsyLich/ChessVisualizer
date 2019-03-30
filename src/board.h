#pragma once
#include "main.h"
int makeaTurn(struct Board *board);
int checkLogic(struct Board *board, int FigureToMakeATurn,
               int startingCellNumber, int startingCellLetter,
               int endingCellNumber, int endingCellLetter);
int turnParse(struct Board *board, int *FigureToMakeATurn);

int checkOnTurnStart(char turn[TURN_CAPACITY]);
int checkOnTurnMove(char turn[TURN_CAPACITY]);
int checkOnTurnEnd(char turn[TURN_CAPACITY]);
int checkOnFigure(char turn[TURN_CAPACITY]);