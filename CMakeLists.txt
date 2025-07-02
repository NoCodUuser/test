cmake_minimum_required(VERSION 3.5)

project(TickTackToe LANGUAGES CXX)

FILE(GLOB_RECURSE LibFiles "include/*.h")
add_custom_target(_TickTackToe_include SOURCES ${LibFiles})

file(GLOB_RECURSE Sources "source/*.cpp")

if(MSVC)
    add_compile_options(/bigobj)
endif(MSVC)

add_executable(TickTackToe ${Sources})

target_include_directories(TickTackToe PUBLIC
                            "${PROJECT_SOURCE_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
)
