cmake_minimum_required (VERSION 3.8)
add_executable (curr_problem divideIntegers.cpp ../TwoPointers/numRange.cpp)
install(TARGETS curr_problem DESTINATION bin)