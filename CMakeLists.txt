cmake_minimum_required(VERSION 3.23)
project(15_puzzle_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(15_puzzle_game main.cpp board/boa/board.hpp board/tile/tile.hpp board/tile/tile.cpp board/boa/board.cpp info.hpp userInput/userin.h)
