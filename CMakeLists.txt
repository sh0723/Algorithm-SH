cmake_minimum_required(VERSION 3.20)

project(Algorithm_SH LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE PROBLEM_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/src/*.cpp")

foreach(source_file IN LISTS PROBLEM_SOURCES)
    file(RELATIVE_PATH relative_file "${CMAKE_SOURCE_DIR}/src" "${source_file}")
    string(REGEX REPLACE "\\.cpp$" "" target_name "${relative_file}")
    string(REGEX REPLACE "[/\\\\ .]" "_" target_name "${target_name}")

    add_executable("${target_name}" "${source_file}")
    target_include_directories("${target_name}" PRIVATE
            "${CMAKE_SOURCE_DIR}/include")
    target_compile_options("${target_name}" PRIVATE
            -Wall
            -Wextra
            -Wshadow
            -Wconversion
            -Wno-sign-conversion)
endforeach()

if(NOT PROBLEM_SOURCES)
    message(STATUS "Add C++ solutions under src/ to create CLion run targets.")
endif()
