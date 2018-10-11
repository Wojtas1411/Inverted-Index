cmake_minimum_required(VERSION 3.12)
project(inverted_index_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(inverted_index_cpp main.cpp record.cpp record.h MapUrlManager.cpp MapUrlManager.h MapRecordsManager.cpp MapRecordsManager.h)