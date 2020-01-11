cmake_minimum_required(VERSION 3.10)

project(easy-tsc VERSION 0.1.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compile library
add_subdirectory(easytsc)
# Compile tests
add_subdirectory(test)
