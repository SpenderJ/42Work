cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(lemin C)
add_subdirectory(libft)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}
  -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG}
  -fno-omit-frame-pointer -fsanitize=address")

file(GLOB_RECURSE lemin_HDRS ${lemin_HDRS} include/lemin/*.h)

add_executable(lem-in ${lemin_HDRS} include/lemin.h
  src/gui.c
  src/lemin.c
  src/parser.c
  src/solve.c
  src/utils.c
  src/vertex.c)
set_property(TARGET lem-in PROPERTY C_STANDARD 90)
target_include_directories(lem-in PUBLIC include)
target_link_libraries(lem-in PUBLIC debug ft ncurses)

target_compile_definitions(lem-in
  PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>)
if (MSVC)
  target_compile_options(lem-in
    PRIVATE /MT$<$<CONFIG:Debug>:d> /Oy /W3
    PRIVATE /D_CRT_SECURE_NO_WARNINGS /Dinline=__inline
    PRIVATE /O$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:x>)
else ()
  target_compile_options(lem-in
    PRIVATE -Wall -Werror -Wextra
    PRIVATE -O$<$<CONFIG:Debug>:0 -g3>$<$<CONFIG:Release>:3>)
endif ()
