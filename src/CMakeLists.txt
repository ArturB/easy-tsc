add_library( easytsc easytsc.cc )
target_include_directories( easytsc INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} )
install(TARGETS easytsc DESTINATION lib64)
install(FILES easytsc.h DESTINATION include)
