All:
	gcc -Wall -Werror -c src/board_print_html.c -o build/board_print_html.o -std=gnu99
	gcc -Wall -Werror -c src/main.c -o build/main.o
	gcc -Wall -Werror -c src/board.c -o build/board.o
	gcc build/board_print_html.o build/main.o build/board.o -o bin/program

Clean:
	