add_executable(easy-tsc.test test.cc)
target_link_libraries(easy-tsc.test PUBLIC easytsc)
install(TARGETS easy-tsc.test DESTINATION bin)
