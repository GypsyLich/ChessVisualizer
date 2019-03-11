#include "tableVis.h"
#include <stdio.h>
#include <string.h>

void tableVis(char cell, FILE *fp) {
    switch (cell) {
    case 32:
        fprintf(fp, R"H(                <td></td>
)H");
        break;
    case 112:
        fprintf(fp,
                R"H(                <td><span class="black pawn"></span></td>
)H");
        break;
    case 114:
        fprintf(fp,
                R"H(                <td><span class="black rook"></span></td>
)H");
        break;
    case 110:
        fprintf(fp,
                R"H(                <td><span class="black knight"></span></td>
)H");
        break;

    case 98:
        fprintf(fp,
                R"H(                <td><span class="black bishop"></span></td>
)H");
        break;
    case 113:
        fprintf(fp,
                R"H(                <td><span class="black queen"></span></td>
)H");
        break;
    case 107:
        fprintf(fp,
                R"H(                <td><span class="black king"></span></td>
)H");
        break;
    case 80:
        fprintf(fp,
                R"H(                <td><span class="white pawn"></span></td>
)H");
        break;
    case 82:
        fprintf(fp,
                R"H(                <td><span class="white rook"></span></td>
)H");
        break;
    case 78:
        fprintf(fp,
                R"H(                <td><span class="white knight"></span></td>
)H");
        break;
    case 66:
        fprintf(fp,
                R"H(                <td><span class="white bishop"></span></td>
)H");
        break;
    case 81:
        fprintf(fp,
                R"H(                <td><span class="white queen"></span></td>
)H");
        break;
    case 75:
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