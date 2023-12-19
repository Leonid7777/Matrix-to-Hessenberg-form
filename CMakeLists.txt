cmake_minimum_required(VERSION 3.22)
project(Hes_rev)

set(CMAKE_CXX_STANDARD 11)
option(BUILD_BLAS "USE BLAS" OFF)

set(CMAKE_CXX_COMPILER "g++")
set(GCC_COVERAGE_COMPILE_FLAGS "-Ofast")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(INCLUDE_PATH "include")

include_directories(${INCLUDE_PATH})

add_library(${CMAKE_PROJECT_NAME})

add_subdirectory(src)

add_subdirectory(test)
