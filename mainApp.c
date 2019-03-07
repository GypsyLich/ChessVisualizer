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

    for (int i = 0; i < 9; ++i) {
        fprintf(fp, R"H(<tr>
)H");
        for (int j = 0; j < 9; ++j) {
            vis(board[i][j], fp);
        }
        fprintf(fp, R"H(</tr>
)H");
    }

    fprintf(fp, R"H(

	  </table>
	</body>
	</html>)H");

    // fclose(fp);
    return 0;
}