add_library( easytsc easytsc.cc )
target_include_directories( easytsc
                            INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include> )
install(TARGETS easytsc
        DESTINATION lib64
        EXPORT easytsc-targets)
install(FILES easytsc.h
        DESTINATION include)
