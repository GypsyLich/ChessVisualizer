#include "tableVis.h"
#include <stdio.h>
#include <string.h>

void tableVis(char cell, FILE *fp) {

    char boardFigures[14] = {' ', 'p', 'n', 'b', 'r', 'q', 'k',
                             'P', 'N', 'B', 'R', 'Q', 'K'};
    printf("%s %s\n", &boardFigures[1], &cell);
    int sw =
        strcmp(&cell, &boardFigures[0]) == 0
            ? 0
            : strcmp(&cell, &boardFigures[1]) == 0
                  ? 11
                  : strcmp(&cell, &boardFigures[7]) == 0
                        ? 21
                        : strcmp(&cell, &boardFigures[2]) == 0
                              ? 12
                              : strcmp(&cell, &boardFigures[8]) == 0
                                    ? 22
                                    : strcmp(&cell, &boardFigures[3]) == 0
                                          ? 13
                                          : strcmp(&cell, &boardFigures[9]) == 0
                                                ? 23
                                                : strcmp(&cell,
                                                         &boardFigures[4]) == 0
                                                      ? 14
                                                      : strcmp(&cell,
                                                               &boardFigures
                                                                   [10]) == 0
                                                            ? 24
                                                            : strcmp(
                                                                  &cell,
                                                                  &boardFigures
                                                                      [5]) == 0
                                                                  ? 15
                                                                  : strcmp(
                                                                        &cell,
                                                                        &boardFigures
                                                                            [11]) ==
                                                                            0
                                                                        ? 25
                                                                        : strcmp(
                                                                              &cell,
                                                                              &boardFigures
                                                                                  [6]) ==
                                                                                  0
                                                                              ? 16
                                                                              : strcmp(
                                                                                    &cell,
                                                                                    &boardFigures
                                                                                        [12]) ==
                                                                                        0
                                                                                    ? 26
                                                                                    : -1;
    switch (sw) {
    case 0:
        fprintf(fp, R"H(                <td></td>
)H");
        break;
    case 1:
        fprintf(fp,
                R"H(                <td><span class="black pawn"></span></td>
)H");
        break;
    case 21:
        fprintf(fp,
                R"H(                <td><span class="white pawn"></span></td>
)H");
        break;
    case 16:
        fprintf(fp,
                R"H(                <td><span class="black king"></span></td>
)H");
        break;
    case 26:
        fprintf(fp,
                R"H(                <td><span class="white king"></span></td>
)H");
        break;
    default:
        fprintf(fp, R"H(                <td>help</td>
)H");
        break;
    }
}

void openHTML(FILE *fp) {

    fprintf(fp, R"H(<!DOCTYPE html>
    <html>
    <head>
      <meta charset="utf-8">
      <title>chessviz</title>
      <style type="text/css">
        table.chessboard {
          border: 5px solid #333;
          border-collapse: collapse;
          height: 320px;
          margin: 20px;
          width: 320px;
        }
        table.chessboard caption {
          text-align: left;
        }
        table.chessboard td {
          background-color: #fff;
          font-size: 25px;
          height: 40px;
          text-align: center;
          vertical-align: middle;
          width: 40px;
        }
        table.chessboard tr:nth-child(odd) td:nth-child(even),
        table.chessboard tr:nth-child(even) td:nth-child(odd) {
          background-color: #999;
        }

        table.chessboard .white.king:before   { content: "\2654"; }
        table.chessboard .white.queen:before  { content: "\2655"; }
        table.chessboard .white.rook:before   { content: "\2656"; }
        table.chessboard .white.bishop:before { content: "\2657"; }
        table.chessboard .white.knight:before { content: "\2658"; }
        table.chessboard .white.pawn:before   { content: "\2659"; }

        table.chessboard .black.king:before   { content: "\265A"; }
        table.chessboard .black.queen:before  { content: "\265B"; }
        table.chessboard .black.rook:before   { content: "\265C"; }
        table.chessboard .black.bishop:before { content: "\265D"; }
        table.chessboard .black.knight:before { content: "\265E"; }
        table.chessboard .black.pawn:before   { content: "\265F"; }
      </style>
    </head>
    <body>
      <table class="chessboard">
        <caption>1. e2-e4</caption>)H");
}

void closeHTML(FILE *fp) {
    fprintf(fp, R"H(

      </table>
    </body>
    </html>)H");
}