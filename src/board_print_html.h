#ifndef __TABLE_VIS_H__
#define __TABLE_VIS_H__

#include <stdio.h>
void boardPrint(int i, char board[8][8]);
void tableVis(char cell, FILE *fp);
void openHTML(FILE *fp);
void closeHTML(FILE *fp);
#endif