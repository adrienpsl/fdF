cmake_minimum_required(VERSION 3.9.4)

project(fdf C)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_COMPILER "/usr/bin/gcc")

set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror")

file(GLOB head "includes/*.h")
#include_directories(${PROJECT_SOURCE_DIR}/include)


file(GLOB sources0 "*.c")
file(GLOB sources1 "sources/src/**/*.c")
file(GLOB sources2 "sources/src/**/**/*.c")
file(GLOB sources3 "sources/src/**/**/**/*.c")
file(GLOB sources4 "sources/src/**/**/**/**/*.c")
file(GLOB sources5 "sources/src/**/**/**/**/**/*.c")
file(GLOB sources6 "test/*.c")


file(GLOB sources00 "src/*.c")
file(GLOB sources01 "src/**/*.c")
file(GLOB sources02 "src/**/**/*.c")
file(GLOB sources03 "src/**/**/**/*.c")
file(GLOB sources04 "src/**/**/**/**/*.c")
file(GLOB sources05 "src/**/**/**/**/**/*.c")

file(GLOB sources06 "test/*.c")

file(GLOB sources07 "header/*.c")
file(GLOB sources08 "header/*.h")

file(GLOB sources000 "mlx/*.c")



# all sources
set(
        sources
        ${sources0}
        ${sources1}
        ${sources2}
        ${sources3}
        ${sources4}
        ${sources5}
        ${sources6}
#
        ${sources00}
        ${sources01}
        ${sources02}
        ${sources03}
        ${sources04}
        ${sources05}
        ${sources06}
        ${sources07}
        ${sources08}
#
#        ${sources000}
        src/lib_graf/draw_line/brain_draw.c src/lib_graf/draw_line/dx_sup_0.c)

add_executable(fdf

        main.c
        ${sources}
        ${head}

        )
target_link_libraries(fdf ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(fdf ${CMAKE_SOURCE_DIR}/mlx/libmlx.a)

target_link_libraries(fdf "-framework OpenGL")
target_link_libraries(fdf "-framework AppKit")

#add_library(mlx STATIC IMPORTED)
#set_property(TARGET mlx PROPERTY IMPORTED_LOCATION ./mlx/libmlx.a)


#add_library(lib STATIC IMPORTED)
#set_property(TARGET lib PROPERTY IMPORTED_LOCATION ../../library/sources/libft.a)


#INCLUDE_DIRECTORIES(./mlx)
#LINK_DIRECTORIES(./mlx)
#
#target_link_libraries (fdf mlx/libmlx.a)