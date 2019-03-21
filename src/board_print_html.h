#pragma once
#include <stdio.h>
void boardPrint(FILE *fp, int i, char turnAction[], char board[8][8]);
void tableVis(char cell, FILE *fp);
void openHTML(FILE *fp);
void closeHTML(FILE *fp);