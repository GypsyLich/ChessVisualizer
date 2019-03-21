#include "main.h"
#include "board.h"
#include "board_print_html.h"
#include <stdio.h>
void intializeBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j].figure =
                i > 1 && i < 6 ? empty
                               : i == 1 || i == 6
                                     ? pawn
                                     : j == 0 || j == 7
                                           ? rook
                                           : j == 1 || j == 6
                                                 ? knight
                                                 : j == 2 || j == 5
                                                       ? bishop
                                                       : j == 3 ? queen : king;
            printf("%d ", board[i][j].figure);
            board[i][j].color = i < 2 ? black : i > 5 ? white : none;
        }
        printf("\n");
    }
}
int main() {
    intializeBoard();
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

        fscanf(logFile, "%s ", turn);
        if (makeaTurn(1)) {
            printf("ERROR: incorect input in turn %d\n", turnNumber);
            return -1;
        }
        boardPrint(htmlFile, turnNumber);
        if (feof(logFile)) {
            break;
        }

        fscanf(logFile, "%s ", turn);
        if (makeaTurn(2)) {
            printf("ERROR: incorect input in turn %d\n", turnNumber);
            return -1;
        }
        boardPrint(htmlFile, turnNumber++);
    }

    fclose(logFile);
    closeHTML(htmlFile);
    fclose(htmlFile);
    return 0;
}