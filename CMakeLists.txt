cmake_minimum_required(VERSION 3.22)
project(prog)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_COMPILER "g++")
set(GCC_COVERAGE_COMPILE_FLAGS "-Ofast")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(INCLUDE_PATH "headers")

include_directories(${INCLUDE_PATH})

add_executable(prog
  src/Hessenberg_form.cpp
  src/multiplication_by_the_reflection_matrix.cpp
  src/reflection_vector.cpp
  src/hessenberg.cpp
  src/creating_matrix.cpp
  src/test.cpp
)

target_link_libraries(prog)
