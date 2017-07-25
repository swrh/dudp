# test/CMakeLists.txt

file (GLOB_RECURSE SOURCES
    ./*.cpp
    ./*.hpp
    )

add_executable (dudp-test
    ${SOURCES}
    )

find_package (Boost 1.54.0 REQUIRED COMPONENTS
    unit_test_framework
    )

target_link_libraries (dudp-test PUBLIC
    dudp
    ${Boost_LIBRARIES}
    )

target_include_directories (dudp-test PUBLIC
    ${Boost_INCLUDE_DIRS}
    )

target_compile_options (dudp-test PUBLIC
    ${Boost_CFLAGS_OTHER}
    )

# vim:set sw=4 ts=4 et:
