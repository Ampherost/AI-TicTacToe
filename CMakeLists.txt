# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and supported languages
project(AI_TicTacToe VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard (e.g., C++11, C++14, C++17)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source files for your Tic-Tac-Toe game
set(SOURCES
    src/main.cpp
    src/board.cpp
    src/ai.cpp
    src/utility.cpp
)

# Define the header files if you want to include them
set(HEADERS
    src/board.hpp
    src/ai.hpp
    src/utility.hpp
)

# Create an executable for your game
add_executable(TicTacToe ${SOURCES} ${HEADERS})

# Enable testing
enable_testing()

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
# Download and add GoogleTest
FetchContent_MakeAvailable(googletest)

# Link GoogleTest to your executable for unit testing
target_link_libraries(TicTacToe PRIVATE gtest gtest_main)

# Add a directory for your unit tests (if you have a Testing directory)
add_subdirectory(test)