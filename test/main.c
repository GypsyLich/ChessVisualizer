#define CTEST_MAIN
#define CTEST_COLOR_OK

#define TURN_CAPACITY 10
#define GIVEN_TURN "e2-e4"
#include <board.h>
#include <board_print_html.h>
#include <ctest.h>

int main(int argc, const char **argv) { return ctest_main(argc, argv); }

/////////INPUT TEST/////////////
CTEST(input_test, pass_figure) {
    // Given
    char turn[TURN_CAPACITY] = GIVEN_TURN;

    // When
    const int result = passFigure(turn);

    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(input_test, pass_turn_start) {
    // Given
    char turn[TURN_CAPACITY] = GIVEN_TURN;

    // When
    const int result = passTurnStart(turn);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(input_test, pass_turn_move) {
    // Given
    char turn[TURN_CAPACITY] = GIVEN_TURN;

    // When
    const int result = passTurnMove(turn);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(input_test, pass_turn_end) {
    // Given
    char turn[TURN_CAPACITY] = GIVEN_TURN;

    // When
    const int result = passTurnEnd(turn);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}
////////////////////////////////

////////MOVE CHECK////////
CTEST(move_check, check_starting_cell) {
    // Given
    int startingCell = 1;
    int figureToMakeATurn = 1;

    // When
    const int result = checkStartingCell(startingCell, figureToMakeATurn);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(move_check, check_resulting_cell) {
    // Given
    int resultingCell = 0;
    char turn[TURN_CAPACITY] = GIVEN_TURN;

    // When
    const int result = checkResultingCellForMove(resultingCell, turn[2]);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}