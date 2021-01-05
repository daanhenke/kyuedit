# Completely arbitrary but cmake complains if it isn't at the top of the file
cmake_minimum_required(VERSION 3.4)
project(kyuedit)

# Enable C++20 features in our compiler
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Build all projects to the same directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Include our external dependencies
add_subdirectory(external)

# Kyulang, the scripting language of kyuedit
add_subdirectory(kyulang)

# The editor itself
add_subdirectory(program)