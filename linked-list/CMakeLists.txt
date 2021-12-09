cmake_minimum_required(VERSION 3.21)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(design-linked-list singly-linked-list/design-linked-list.cpp)
add_executable(linked-list-cycle two-pointer-technique/linked-list-cycle.cpp)
add_executable(linked-list-cycle-two two-pointer-technique/linked-list-cycle-two.cpp)
add_executable(intersection-of-two-linked-lists two-pointer-technique/intersection-of-two-linked-lists.cpp)
add_executable(remove-nth-node-from-end-of-list two-pointer-technique/remove-nth-node-from-end-of-list.cpp)
