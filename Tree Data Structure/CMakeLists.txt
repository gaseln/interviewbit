cmake_minimum_required (VERSION 3.8)
add_executable (curr_problem identicalBinaryTrees.cpp ../QRound_CodeJam_2020/problem1.cpp)
install(TARGETS curr_problem DESTINATION bin)