cmake_minimum_required(VERSION 3.22)
project(prog)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_COMPILER "g++")
set(GCC_COVERAGE_COMPILE_FLAGS "-Ofast")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(prog
  Hessenberg_form.cpp
  l_mul.cpp
  r_mul.cpp
  make_vector.cpp
)

target_link_libraries(prog)
