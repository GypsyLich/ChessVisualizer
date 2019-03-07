#include "tableViz.h"
#include <stdio.h>

void vis(char cell, FILE *fp) {
    switch (cell) {
        case " "
        	fprintf(fp, R"H(	      <td></td>
        		)H");
		break;
		case "p"
			fprintf(fp, R"H(	      <td><span class="black pawn"></span></td>
				)H");
		break;
		case "P"
			fprintf(fp, R"H(	      <td><span class="white pawn"></span></td>
				)H");
		break;
		case "k"
			fprintf(fp, R"H(	      <td><span class="black king"></span></td>
				)H");
		break;
		case "K"
			fprintf(fp, R"H(	      <td><span class="white king"></span></td>
				)H");
		break;
		default
			fprintf(fp, R"H(	      <td></td>
				)H");
		break;
	}
}