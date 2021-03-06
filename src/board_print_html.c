#include "board_print_html.h"
#include <stdio.h>
#include <string.h>

void boardPrint(struct Board *board, FILE *fp, int turnNumber) {

    fprintf(fp, R"H(<table class="chessboard"><caption>)H");
    fprintf(fp, "%d. %s</caption>\n", turnNumber, board->turn);

    for (int i = 0; i < 8; ++i) {
        fprintf(fp, R"H(<tr>)H");
        for (int j = 0; j < 8; ++j) {
            tableVis(board, i, j, fp);
        }
        fprintf(fp, R"H(</tr>)H");
    }

    fprintf(fp, R"H(</table>)H");
}

void tableVis(struct Board *board, int i, int j, FILE *fp) {
    int sw = board->thisCell[i][j].colorOfTheFigure == black ? 10 : 1;
    switch (board->thisCell[i][j].figure * sw) {
    case 0:
        fprintf(fp, R"H(                <td></td>)H");
        break;
    case 10:
        fprintf(
            fp,
            R"H(                <td><span class="black pawn"></span></td>)H");
        break;
    case 20:
        fprintf(
            fp,
            R"H(                <td><span class="black rook"></span></td>)H");
        break;
    case 30:
        fprintf(
            fp,
            R"H(                <td><span class="black knight"></span></td>)H");
        break;

    case 40:
        fprintf(
            fp,
            R"H(                <td><span class="black bishop"></span></td>)H");
        break;
    case 50:
        fprintf(
            fp,
            R"H(                <td><span class="black queen"></span></td>)H");
        break;
    case 60:
        fprintf(
            fp,
            R"H(                <td><span class="black king"></span></td>)H");
        break;
    case 1:
        fprintf(
            fp,
            R"H(                <td><span class="white pawn"></span></td>)H");
        break;
    case 2:
        fprintf(
            fp,
            R"H(                <td><span class="white rook"></span></td>)H");
        break;
    case 3:
        fprintf(
            fp,
            R"H(                <td><span class="white knight"></span></td>)H");
        break;
    case 4:
        fprintf(
            fp,
            R"H(                <td><span class="white bishop"></span></td>)H");
        break;
    case 5:
        fprintf(
            fp,
            R"H(                <td><span class="white queen"></span></td>)H");
        break;
    case 6:
        fprintf(
            fp,
            R"H(                <td><span class="white king"></span></td>)H");
        break;
    default:
        fprintf(fp, R"H(                <td>help</td>)H");
        break;
    }
}

void openHTML(FILE *fp) {

    fprintf(
        fp,
        R"H(<!DOCTYPE html><html><head><meta charset="utf-8"><title>chessviz</title><style type="text/css">table.chessboard {border: 5px solid #333;border-collapse: collapse;height: 320px;margin: 20px;width: 320px;}table.chessboard caption {text-align: left;}table.chessboard td {background-color: #fff;font-size: 25px;height: 40px;text-align: center;vertical-align: middle;width: 40px;}table.chessboard tr:nth-child(odd) td:nth-child(even),table.chessboard tr:nth-child(even) td:nth-child(odd) {background-color: #999;}table.chessboard .white.king:before   { content: "\2654"; }table.chessboard .white.queen:before  { content: "\2655"; }table.chessboard .white.rook:before   { content: "\2656"; }table.chessboard .white.bishop:before { content: "\2657"; }table.chessboard .white.knight:before { content: "\2658"; }table.chessboard .white.pawn:before   { content: "\2659"; }table.chessboard .black.king:before   { content: "\265A"; }table.chessboard .black.queen:before  { content: "\265B"; }table.chessboard .black.rook:before   { content: "\265C"; }table.chessboard .black.bishop:before { content: "\265D"; }table.chessboard .black.knight:before { content: "\265E"; }table.chessboard .black.pawn:before   { content: "\265F"; }</style></head><body>)H");
}

void closeHTML(FILE *fp) { fprintf(fp, R"H(</body></html>)H"); }