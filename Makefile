All: program

program: main.o board.o board_print_html.o
	gcc build/board_print_html.o build/main.o build/board.o -o bin/program

main.o: ./src/main.c ./src/main.h
	gcc -Wall -Werror -c src/main.c -o build/main.o -std=gnu99

board.o: ./src/board.c ./src/board.h ./src/main.h
	gcc -Wall -Werror -c src/board.c -o build/board.o -std=gnu99

board_print_html.o: ./src/board_print_html.c ./src/board_print_html.h ./src/main.h
	gcc -Wall -Werror -c src/board_print_html.c -o build/board_print_html.o -std=gnu99

Clean:
	rm -f /build/*.o

	