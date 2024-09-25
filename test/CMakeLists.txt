# Add an executable for running your tests
add_executable(runTests tictactoeTest.cpp)  # Make sure to include your new test file here

# Link GoogleTest and your main TicTacToe game code to the test executable
target_link_libraries(runTests PRIVATE gtest gtest_main TicTacToeCore)

# Register the tests with CTest
add_test(NAME TicTacToeTests COMMAND runTests)
