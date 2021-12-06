cmake_minimum_required(VERSION 3.21)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror -g)

add_executable(find-pivot-index introduction-to-array/find-pivot-index.cpp)
add_executable(largest-number-at-least-twice introduction-to-array/largest-number-at-least-twice.cpp)
add_executable(plus-one introduction-to-array/plus-one.cpp)

add_executable(diagonal-traverse introduction-to-2D-array/diagonal-traverse.cpp)
add_executable(spiral-matrix introduction-to-2D-array/spiral-matrix.cpp)
