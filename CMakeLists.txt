cmake_minimum_required(VERSION 3.15)

# Project name and version
project(easytsc VERSION 0.1.1)

# Language standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include local macros
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR})
# include(RequireLibrary)

# Compiler flags
set( CMAKE_CXX_FLAGS "-Wall " )

# Debug and release build
set( CMAKE_BUILD_TYPE "debug" ) # By default, we run debug build
if ( CMAKE_BUILD_TYPE MATCHES "debug" )
    string ( APPEND CMAKE_CXX_FLAGS "-g -DDEBUG " ) # Debug build compiler flags
endif ( CMAKE_BUILD_TYPE MATCHES "debug" )
if ( CMAKE_BUILD_TYPE MATCHES "release" )
    string ( APPEND CMAKE_CXX_FLAGS "-DNDEBUG -O3 " ) # Release build compiler flags
endif ( CMAKE_BUILD_TYPE MATCHES "release" )

# Output dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Compile sources
add_subdirectory(src)
# Compile tests
add_subdirectory(test)

# Print configuration
message("
-------------------------------------------------------

Build type:        ${CMAKE_BUILD_TYPE}
Project generator: ${CMAKE_GENERATOR}
Install prefix:    ${CMAKE_INSTALL_PREFIX}
Compiler flags:
    CXX:            ${CMAKE_CXX_COMPILER}
    CXXFLAGS:       ${CMAKE_CXX_FLAGS}
")
