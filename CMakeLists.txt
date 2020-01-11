cmake_minimum_required(VERSION 3.10)

# set the project name
project(easy-tsc VERSION 0.1.1)
# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(include)
add_executable(easy-tsc-test test/test.cc)

target_link_libraries(easy-tsc-test PUBLIC include)
target_include_directories(easy-tsc-test PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/include"
                          )
