#include "board.h"
#include "board_print_html.h"
#include <stdio.h>
int main() {
    char board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    char turn[10];

    int turnNumber = 1;
    FILE *htmlFile;
    htmlFile = fopen("bin/h.html", "w");
    FILE *logFile;
    logFile = fopen("bin/turnsLog.txt", "r");
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
        if (makeaTurn(turn, 1, &board)) {
            printf("ERROR: incorect input in turn %d\n", turnNumber);
            return -1;
        }
        makeaTurn(turn, 1, &board);
        boardPrint(htmlFile, turnNumber, turn, board);
        if (feof(logFile)) {
            break;
        }

        fscanf(logFile, "%s ", turn);
        if (makeaTurn(turn, 2, &board)) {
            printf("ERROR: incorect input in turn %d\n", turnNumber);
            return -1;
        }
        boardPrint(htmlFile, turnNumber++, turn, board);
    }

    fclose(logFile);
    closeHTML(htmlFile);
    fclose(htmlFile);
    return 0;
}