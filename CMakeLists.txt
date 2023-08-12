cmake_minimum_required(VERSION 3.23)
project(15_puzzle_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(15_puzzle_game main.cpp gameBoard/board/board.hpp gameBoard/board/board.cpp gameBoard/tile/tile.hpp gameBoard/tile/tile.cpp)
