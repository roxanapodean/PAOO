cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Main VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_subdirectory(student)

# add the executable
add_executable(Main main.cpp)

target_link_libraries(Main PUBLIC student)

target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/student")

