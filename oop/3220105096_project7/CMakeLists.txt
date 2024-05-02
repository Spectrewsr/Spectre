# FILEPATH: /mnt/d/class/grade2second/oop/3220105096_project7/CMakeLists.txt

# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0.0)

# Set the project name and version
project(demo VERSION 0.1.0 LANGUAGES C CXX)

# Include CTest module for testing
include(CTest)
enable_testing()

# Add the 'src' subdirectory
add_subdirectory(src)

# Set CPack variables for packaging
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

