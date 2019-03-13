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
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    remove("bin/h.html");

    FILE *htmlFile;
    htmlFile = fopen("bin/h.html", "w+");
    FILE *logFile;
    logFile = fopen("bin/turnsLog.txt", "r");
    if (logFile == NULL) {
        printf("ERROR: Turns log file(bin/turnsLog.txt) is missing \n");
        return -1;
    }

    while (1) {
        fscanf(logFile, "%s ", turn);
        printf("%s\n", turn);
        if (feof(logFile)) {
            break;
        }
    }
    fclose(logFile);

    openHTML(htmlFile);

    boardPrint(htmlFile, 1, "e2-e4", board);

    closeHTML(htmlFile);
    fclose(htmlFile);
    return 0;
}