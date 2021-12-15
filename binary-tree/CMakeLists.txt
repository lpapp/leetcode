cmake_minimum_required(VERSION 3.21)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(binary-tree-preorder-traversal traverse-a-tree/binary-tree-preorder-traversal.cpp)
add_executable(binary-tree-inorder-traversal traverse-a-tree/binary-tree-inorder-traversal.cpp)
add_executable(binary-tree-postorder-traversal traverse-a-tree/binary-tree-postorder-traversal.cpp)
add_executable(binary-tree-level-order-traversal traverse-a-tree/binary-tree-level-order-traversal.cpp)

add_executable(maximum-depth-of-binary-tree solve-problems-recursively/maximum-depth-of-binary-tree.cpp)
add_executable(symmetric-tree solve-problems-recursively/symmetric-tree.cpp)
