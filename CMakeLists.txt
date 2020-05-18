cmake_minimum_required(VERSION 3.10)
project(CPPproject)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(CPPproject Vector0.cpp main.cpp cmake-build-debug/Matrix0.cpp cmake-build-debug/Matrix0.h)