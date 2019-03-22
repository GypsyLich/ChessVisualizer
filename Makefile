
BIN_DIR := ./bin/
BUILD_DIR := ./build/
SRC_DIR := ./src/

All: $(BIN_DIR)program

$(BIN_DIR)program: $(BUILD_DIR)main.o $(BUILD_DIR)board.o $(BUILD_DIR)board_print_html.o
	gcc build/board_print_html.o build/main.o build/board.o -o $(BIN_DIR)program

$(BUILD_DIR)main.o: $(SRC_DIR)main.c $(SRC_DIR)main.h
	gcc -Wall -Werror -c src/main.c -o build/main.o -std=gnu99

$(BUILD_DIR)board.o: $(SRC_DIR)board.c $(SRC_DIR)board.h $(SRC_DIR)main.h
	gcc -Wall -Werror -c src/board.c -o build/board.o -std=gnu99

$(BUILD_DIR)board_print_html.o: $(SRC_DIR)board_print_html.c $(SRC_DIR)board_print_html.h $(SRC_DIR)main.h
	gcc -Wall -Werror -c src/board_print_html.c -o build/board_print_html.o -std=gnu99

Clean:
	rm -f /build/*.o

	