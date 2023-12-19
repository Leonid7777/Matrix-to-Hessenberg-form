target_sources(${CMAKE_PROJECT_NAME}
  PRIVATE
  apply_reflection.cpp
  reflection_vector.cpp
  hessenberg.cpp
  creating_matrix.cpp
)

if(BUILD_BLAS)
  find_package(LAPACK REQUIRED)
  target_link_libraries(${CMAKE_PROJECT_NAME}
    ${LAPACK_LIBRARIES}
  )
  target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE USE_BLAS)
else()
  target_link_libraries(${CMAKE_PROJECT_NAME})
endif()
