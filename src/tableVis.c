#include "tableVis.h"
#include <stdio.h>

void tableVis(char cell, FILE *fp) {
    int sw =
        cell == " "
            ? 0
            : cell == "p"
                  ? 11
                  : cell == "P"
                        ? 21
                        : cell == "n"
                              ? 12
                              : cell == "N"
                                    ? 22
                                    : cell == "b"
                                          ? 13
                                          : cell == "B"
                                                ? 23
                                                : cell == "r"
                                                      ? 14
                                                      : cell == "R"
                                                            ? 24
                                                            : cell == "q"
                                                                  ? 15
                                                                  : cell == "Q"
                                                                        ? 25
                                                                        : cell == "k"
                                                                              ? 16
                                                                              : cell == "K"
                                                                                    ? 26
                                                                                    : -1;
    switch (sw) {
    case 0:
        fprintf(fp, R"H(          <td></td>
                )H");
        break;
    case 1:
        fprintf(fp, R"H(          <td><span class="black pawn"></span></td>
                )H");
        break;
    case 21:
        fprintf(fp, R"H(          <td><span class="white pawn"></span></td>
                )H");
        break;
    case 16:
        fprintf(fp, R"H(          <td><span class="black king"></span></td>
                )H");
        break;
    case 26:
        fprintf(fp, R"H(          <td><span class="white king"></span></td>
                )H");
        break;
    default:
        fprintf(fp, R"H(          <td></td>
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