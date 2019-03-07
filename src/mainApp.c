#include "tableVis.h"
#include <stdio.h>
int main() {
    char board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {'#', ' ', '#', ' ', '#', ' ', '#', ' '},
                        {' ', '#', ' ', '#', ' ', '#', ' ', '#'},
                        {'#', ' ', '#', ' ', '#', ' ', '#', ' '},
                        {' ', '#', ' ', '#', ' ', '#', ' ', '#'},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    FILE *fp;
    fp = fopen("h.html", "w+");
    openHTML(fp);
    for (int i = 0; i < 9; ++i) {
        fprintf(fp, R"H(<tr>
)H");
        for (int j = 0; j < 9; ++j) {
            tableVis(board[i][j], fp);
        }
        fprintf(fp, R"H(</tr>
)H");
    }
    closeHTML(fp);
    fclose(fp);
    return 0;
}