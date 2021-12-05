cmake_minimum_required(VERSION 3.21)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror -g)

add_executable(max-consecutive-ones introduction/max-consecutive-ones.cpp)
add_executable(even-number-of-digits introduction/even-number-of-digits.cpp)
add_executable(squares-of-sorted-array introduction/squares-of-sorted-array.cpp)

add_executable(duplicate-zeros inserting/duplicate-zeros.cpp)
add_executable(merge-sorted-array inserting/merge-sorted-array.cpp)

add_executable(remove-element deleting/remove-element.cpp)
add_executable(remove-duplicates-from-sorted-array deleting/remove-duplicates-from-sorted-array.cpp)

add_executable(check-if-exist searching/check-if-exist.cpp)
add_executable(valid-mountain-array searching/valid-mountain-array.cpp)

add_executable(replace-elements in-place/replace-elements.cpp)
add_executable(remove-duplicates in-place/remove-duplicates.cpp)
add_executable(move-zeroes in-place/move-zeroes.cpp)
add_executable(sort-array-by-parity in-place/sort-array-by-parity.cpp)
add_executable(remove-element-in-place in-place/remove-element.cpp)

add_executable(height-checker conclusion/height-checker.cpp)
add_executable(third-maximum-number conclusion/third-maximum-number.cpp)
add_executable(find-disappeared-numbers conclusion/find-disappeared-numbers.cpp)
