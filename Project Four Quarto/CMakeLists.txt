cmake_minimum_required(VERSION 3.8)
project(p4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp exceptions.h exceptions.cpp pool.h piece.h player.h quarto.h square.h quarto.cpp piece.cpp pool.cpp square.cpp board.h board.cpp player.cpp)
add_executable(p4 ${SOURCE_FILES})