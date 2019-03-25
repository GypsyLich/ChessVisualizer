#include "main.h"
#include "board.h"
#include "board_print_html.h"
#include <stdio.h>
#include <stdlib.h>
struct Board *intializeBoard() {
    struct Board *board = malloc(sizeof(*board));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int sw = i == 1 || i == 6 ? 10 : j;
            sw += i > 1 && i < 6 ? 11 : 0;
            switch (sw) {
            case 10:
                board->thisCell[i][j].figure = pawn;
                break;
            case 0:
                board->thisCell[i][j].figure = rook;
            case 7:
                board->thisCell[i][j].figure = rook;
                break;
            case 1:
                board->thisCell[i][j].figure = knight;
            case 6:
                board->thisCell[i][j].figure = knight;
                break;
            case 2:
                board->thisCell[i][j].figure = bishop;
            case 5:
                board->thisCell[i][j].figure = bishop;
                break;
            case 3:
                board->thisCell[i][j].figure = queen;
                break;
            case 4:
                board->thisCell[i][j].figure = king;
                break;
            default:
                board->thisCell[i][j].figure = empty;
                break;
            }
            printf("%d ", board->thisCell[i][j].figure);
            board->thisCell[i][j].colorOfTheFigure =
                i < 2 ? black : i > 5 ? white : none;
        }
        printf("\n");
    }
    return board;
}
int main() {
    struct Board *board = intializeBoard();
    int turnNumber = 1;
    FILE *htmlFile;
    htmlFile = fopen("h.html", "w");
    FILE *logFile;
    logFile = fopen("turnsLog.txt", "r");
    if (logFile == NULL) {
        printf("ERROR: Turns log file(bin/turnsLog.txt) is missing \n");
        return -1;
    }

    openHTML(htmlFile);

    while (1) {
        if (feof(logFile)) {
            break;
        }

        fscanf(logFile, "%s ", board->turn);
        if (makeaTurn(board)) {
            printf("ERROR: incorect input in turn %d\n", turnNumber);
            return -1;
        }
        boardPrint(board, htmlFile, turnNumber);
        if (feof(logFile)) {
            break;
        }

        fscanf(logFile, "%s ", board->turn);
        if (makeaTurn(board)) {
            printf("ERROR: incorect input in turn %d\n", turnNumber);
            return -1;
        }
        boardPrint(board, htmlFile, turnNumber++);
    }

    fclose(logFile);
    closeHTML(htmlFile);
    fclose(htmlFile);
    return 0;
}