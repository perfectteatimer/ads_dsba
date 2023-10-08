cmake_minimum_required(VERSION 3.24)
project(algorithmsDSBA_)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorithmsDSBA_ main.cpp)
add_executable(seminar1 seminar1-06-09-23-mergesort/merge-sort.cpp)
add_executable(seminar2 seminar2-06-09-23-countsort/exercise-countsort.cpp)
add_executable(seminar3_4_1 seminar3-4-11-09-23-heapsort/heap-exercise1/main.cpp)
add_executable(seminar3_4_2 seminar3-4-11-09-23-heapsort/heap-exercise2/kLargestElement.cpp)
add_executable(seminar3_4_3 seminar3-4-11-09-23-heapsort/heap-exercise3/kClosestOrigin.cpp)
add_executable(seminar5_0 seminar5-18-09-23-chrono-radixsort/benchmark.cpp)
add_executable(seminar5_1 seminar5-18-09-23-chrono-radixsort/radixsort-exercise.cpp)
add_executable(binarytrees BSTrees/exercises.cpp)