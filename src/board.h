#pragma once
#include "main.h"
int makeaTurn(struct Board *board);
int checkLogic(struct Board *board, int FigureToMakeATurn,
               int startingCellNumber, int startingCellLetter,
               int endingCellNumber, int endingCellLetter);
int turnParse(struct Board *board, int *FigureToMakeATurn);