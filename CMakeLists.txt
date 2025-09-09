set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.10)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ppm)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/jpg)

# Automatically find all C source files in src/
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
)

# Automatically find all header files in src/
file(GLOB_RECURSE HEADERS 
    "src/*.hpp"
)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create the executable
add_executable(raytracer ${SOURCES} ${HEADERS})

# Include directories (so #include "header.h" works from anywhere)
target_include_directories(raytracer PRIVATE src)
