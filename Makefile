
BIN_DIR := ./bin
BUILD_DIR := ./build
SRC_DIR := ./src
TEST_DIR := ./test
BUILD_TEST_DIR := ./build/test

All: $(BIN_DIR)/program

$(BIN_DIR)/program: $(BUILD_DIR)/main.o $(BUILD_DIR)/board.o $(BUILD_DIR)/board_print_html.o
	gcc $(BUILD_DIR)/board_print_html.o $(BUILD_DIR)/main.o $(BUILD_DIR)/board.o -o $(BIN_DIR)/program

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c 
	gcc -Wall -Werror -c $(SRC_DIR)/main.c -o $(BUILD_DIR)/main.o -std=gnu99

$(BUILD_DIR)/board.o: $(SRC_DIR)/board.c $(SRC_DIR)/board.h 
	gcc -Wall -Werror -c $(SRC_DIR)/board.c -o $(BUILD_DIR)/board.o -std=gnu99

$(BUILD_DIR)/board_print_html.o: $(SRC_DIR)/board_print_html.c $(SRC_DIR)/board_print_html.h $(SRC_DIR)/main.h
	gcc -Wall -Werror -c $(SRC_DIR)/board_print_html.c -o $(BUILD_DIR)/board_print_html.o -std=gnu99




Test: $(TEST_DIR)/test

$(TEST_DIR)/test: $(BUILD_TEST_DIR)/main.o $(BUILD_TEST_DIR)/board.o $(BUILD_TEST_DIR)/board_print_html.o
	gcc $(BUILD_TEST_DIR)/board_print_html.o $(BUILD_TEST_DIR)/main.o $(BUILD_TEST_DIR)/board.o -o $(TEST_DIR)/test


$(BUILD_TEST_DIR)/main.o: $(TEST_DIR)/main.c 
	gcc -Wall -c -I thirdparty src $(TEST_DIR)/main.c -o $(BUILD_TEST_DIR)/main.o -std=gnu99

$(BUILD_TEST_DIR)/board.o: $(SRC_DIR)/board.c $(SRC_DIR)/board.h $(SRC_DIR)/main.h
	gcc -Wall -c -I thirdparty src $(SRC_DIR)/board.c -o $(BUILD_TEST_DIR)/board.o -std=gnu99

$(BUILD_TEST_DIR)/board_print_html.o: $(SRC_DIR)/board_print_html.c $(SRC_DIR)/board_print_html.h $(SRC_DIR)/main.h
	gcc -Wall -c -I thirdparty src $(SRC_DIR)/board_print_html.c -o $(BUILD_TEST_DIR)/board_print_html.o -std=gnu99

Clean:
	rm -f /$(BUILD_DIR)/*.o

	