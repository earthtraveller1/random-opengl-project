cmake_minimum_required(VERSION "3.16")

project("random-opengl-project")

# Use C++17
set(CMAKE_CXX_STANDARD 17)
# Where the package finders are
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Options
option(BUILD_SHARED_LIBS DOC "Wether or not to build shared libraries.")

# Find the libraries
find_package("GLFW")

# Set the includes
include_directories("${GLFW_INCLUDE_DIR}" "include")

# Turn on high warning levels
if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-pedantic")
endif()

add_executable("random-opengl-project")

add_subdirectory("src")