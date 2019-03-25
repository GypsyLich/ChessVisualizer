#pragma once
#include "main.h"
#include <stdio.h>
void boardPrint(struct Board *board, FILE *fp, int i);
void tableVis(struct Board *board, int i, int j, FILE *fp);
void openHTML(FILE *fp);
void closeHTML(FILE *fp);