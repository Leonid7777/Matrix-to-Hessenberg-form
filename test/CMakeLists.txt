add_executable(test
  test.cpp
  test.h
  Hessenberg_form.cpp
)

target_link_libraries(test
${CMAKE_PROJECT_NAME}
)