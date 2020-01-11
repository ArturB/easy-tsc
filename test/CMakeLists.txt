add_executable(test test.cc)
target_link_libraries(test PUBLIC easytsc)
target_include_directories(test PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/easytsc"
                          )
