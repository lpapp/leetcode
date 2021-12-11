cmake_minimum_required(VERSION 3.21)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(design-linked-list singly-linked-list/design-linked-list.cpp)

add_executable(linked-list-cycle two-pointer-technique/linked-list-cycle.cpp)
add_executable(linked-list-cycle-two two-pointer-technique/linked-list-cycle-two.cpp)
add_executable(intersection-of-two-linked-lists two-pointer-technique/intersection-of-two-linked-lists.cpp)
add_executable(remove-nth-node-from-end-of-list two-pointer-technique/remove-nth-node-from-end-of-list.cpp)

add_executable(reverse-linked-list classic-problems/reverse-linked-list.cpp)
add_executable(remove-linked-list-elements classic-problems/remove-linked-list-elements.cpp)
add_executable(odd-even-linked-list classic-problems/odd-even-linked-list.cpp)
add_executable(palindrome-linked-list classic-problems/palindrome-linked-list.cpp)

add_executable(design-linked-list-doubly doubly-linked-list/design-linked-list.cpp)

add_executable(merge-two-sorted-lists conclusion/merge-two-sorted-lists.cpp)
