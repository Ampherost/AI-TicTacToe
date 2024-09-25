# Add an executable for your tests
add_executable(runTests test_board.cpp)  # Add all your test source files here

# Link GoogleTest and your main TicTacToe executable to the test executable
target_link_libraries(runTests PRIVATE gtest gtest_main TicTacToe)

# Register the test executable with CTest
add_test(NAME TicTacToeTests COMMAND runTests)
