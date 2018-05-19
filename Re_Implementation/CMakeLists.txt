cmake_minimum_required(VERSION 3.10)
project(Re_Implementation)

set(CMAKE_CXX_STANDARD 17)

set(BUILD1 QuickSort)
set(BUILD1_FILES main.cpp QuickSort.h)
add_executable(${BUILD1} ${BUILD1_FILES})

set(BUILD2 BST)
set(BUILD2_FILES main.cpp BST.h)
add_executable(${BUILD2} ${BUILD2_FILES})

set(BUILD3 Single_ll)
set(BUILD3_FILES main2.cpp Single_ll.h)
add_executable(${BUILD3} ${BUILD3_FILES})