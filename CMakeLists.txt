cmake_minimum_required(VERSION 3.21)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror -g -fsanitize=address)
add_link_options(-fsanitize=address)

add_subdirectory(arrays-101)
add_subdirectory(array-and-string)
add_subdirectory(linked-list)
add_subdirectory(binary-tree)
add_subdirectory(misc)
