# src/CMakeLists.txt

file (GLOB_RECURSE SOURCES
    ../include/*.hpp
    ./*.cpp
    ./*.hpp
    )

add_library (dudp SHARED
    ${SOURCES}
    )

find_package (Boost 1.54.0 REQUIRED COMPONENTS
    system
    )

target_link_libraries (dudp PUBLIC
    ${Boost_LIBRARIES}
    )

target_include_directories (dudp PUBLIC
    ${Boost_INCLUDE_DIRS}
    ../include
    )

target_compile_options (dudp PUBLIC
    ${Boost_CFLAGS_OTHER}
    )

# vim:set sw=4 ts=4 et:
