cmake_minimum_required(VERSION 3.21)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(find-pivot-index introduction-to-array/find-pivot-index.cpp)
add_executable(largest-number-at-least-twice introduction-to-array/largest-number-at-least-twice.cpp)
add_executable(plus-one introduction-to-array/plus-one.cpp)

add_executable(diagonal-traverse introduction-to-2D-array/diagonal-traverse.cpp)
add_executable(spiral-matrix introduction-to-2D-array/spiral-matrix.cpp)
add_executable(pascals-triangle introduction-to-2D-array/pascals-triangle.cpp)

add_executable(add-binary introduction-to-string/add-binary.cpp)
add_executable(strstr introduction-to-string/strstr.cpp)
add_executable(longest-common-prefix introduction-to-string/longest-common-prefix.cpp)

add_executable(reverse-string two-pointer-technique/reverse-string.cpp)
add_executable(array-partition-one two-pointer-technique/array-partition-one.cpp)
add_executable(two-sum-two two-pointer-technique/two-sum-two.cpp)
add_executable(remove-element-two-pointer-technique two-pointer-technique/remove-element.cpp)
add_executable(max-consecutive-ones-two-pointer-technique two-pointer-technique/max-consecutive-ones.cpp)
add_executable(minimum-size-subarray-sum two-pointer-technique/minimum-size-subarray-sum.cpp)

add_executable(rotate-array conclusion/rotate-array.cpp)
add_executable(pascals-triangle-two conclusion/pascals-triangle-two.cpp)
