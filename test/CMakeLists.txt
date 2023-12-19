add_executable(test
  test.cpp
  test.h
  Hessenbrerg_form.cpp
)

target_link_libraries(test
${CMAKE_PROJECT_NAME}
)