All:
	gcc -Wall -Werror -c src/board_print_html.c -o build/board_print_html.o
	gcc -Wall -Werror -c src/main.c -o build/main.o
	gcc build/board_print_html.o build/main.o -o program

Clean:
	