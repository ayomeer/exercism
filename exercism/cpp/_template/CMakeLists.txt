cmake_minimum_required(VERSION 3.5.1)

get_filename_component(exercise ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${exercise} CXX)

set(CMAKE_BUILD_TYPE Debug)
add_executable(mytest quick_test.cpp) 