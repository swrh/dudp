# src/CMakeLists.txt

file (GLOB_RECURSE SOURCES
    ../include/*.hpp
    ./*.cpp
    ./*.hpp
    )

add_library (dudp SHARED
    ${SOURCES}
    )

target_include_directories (dudp PUBLIC
    ../include
    )

# vim:set sw=4 ts=4 et:
