# CMakeLists.txt

cmake_minimum_required (VERSION 3.1 FATAL_ERROR)

project (dudp)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_subdirectory (src)
add_subdirectory (test)

# vim:set sw=4 ts=4 et:
