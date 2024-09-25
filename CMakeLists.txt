# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.30)

# Project name and supported languages
project(AI_TicTacToe VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the header and source files for your Tic-Tac-Toe game
set(HEADERS
    src/board.hpp
    src/ai.hpp
    src/utility.hpp
)

set(SOURCES
    src/main.cpp
    src/board.cpp
    src/ai.cpp
    src/utility.cpp
)

# Create a library for the Tic-Tac-Toe core logic
add_library(TicTacToeCore ${SOURCES})
target_include_directories(TicTacToeCore PUBLIC src)

# Create an executable for your game
add_executable(TicTacToe src/main.cpp)
target_link_libraries(TicTacToe PRIVATE TicTacToeCore)

# Enable testing
enable_testing()

# Manually add GoogleTest from the googletest/ directory
add_subdirectory(googletest)  # Add GoogleTest's CMake files

# Add a subdirectory for your unit tests (this will contain a separate CMakeLists.txt)
add_subdirectory(test)