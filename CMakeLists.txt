cmake_minimum_required(VERSION 3.10)

project(easytsc VERSION 0.1.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Output dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CPACK_OUTPUT_FILE_PREFIX ${CMAKE_BINARY_DIR}/dist)

# Compile library
add_subdirectory(src)
# Compile tests
add_subdirectory(test)

# CPack Installer
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "${easytsc_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${easytsc_VERSION_MINOR}")
include(CPack)

# CMake export
install(EXPORT easytsc-targets
        FILE easytsc-targets.cmake
        DESTINATION lib64/cmake/easytsc-targets
)
include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/easytsc-config.cmake"
  INSTALL_DESTINATION "lib64/cmake/easytsc"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  )
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/easytsc-config-version.cmake"
  VERSION "${easytsc_VERSION_MAJOR}.${easytsc_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/easytsc-config.cmake
  DESTINATION lib64/cmake/easytsc
  )
