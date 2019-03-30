#define CTEST_MAIN
#define CTEST_COLOR_OK

#define TURN_CAPACITY 10
#define GIVEN_TURN "e2-e4"
#include <board.h>
#include <board_print_html.h>
#include <ctest.h>

int main(int argc, const char **argv) { return ctest_main(argc, argv); }

CTEST(input_test, check_on_figure) {
    // Given
    char turn[TURN_CAPACITY] = GIVEN_TURN;

    // When
    const int result = checkOnFigure(turn);

    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(input_test, check_on_turn_start) {
    // Given
    char turn[TURN_CAPACITY] = GIVEN_TURN;

    // When
    const int result = checkOnTurnStart(turn);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(input_test, check_on_turn_move) {
    // Given
    char turn[TURN_CAPACITY] = GIVEN_TURN;

    // When
    const int result = checkOnTurnMove(turn);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(input_test, check_on_turn_end) {
    // Given
    char turn[TURN_CAPACITY] = GIVEN_TURN;

    // When
    const int result = checkOnTurnEnd(turn);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}