cmake_minimum_required(VERSION 3.13)
project(ALG_C)

set(CMAKE_CXX_STANDARD 14)

add_executable(ALG_C work_3/_BFS.cpp work_3/_topo_sort.cpp work_3/1_assignment_munkres.cpp work_3/2_KD_tree.cpp work_3/3_shell_sort.cpp work_3/4_chessboard_coverage.cpp)