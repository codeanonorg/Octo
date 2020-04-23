cmake_minimum_required(VERSION 3.1)

project(Octo)

find_package(Python 3.8 COMPONENTS Interpreter Development REQUIRED)

# LIBRARIES
add_library(cli OBJECT ./cli/cli.c)
add_library(io OBJECT ./io/io.c)

# EXECUTABLE
add_executable(octo
  $<TARGET_OBJECTS:cli>
  octo.c)

add_executable(test test.c)

target_include_directories(octo PUBLIC ./)
target_include_directories(test PUBLIC ${Python_INCLUDE_DIRS})
target_link_libraries(test ${Python_LIBRARIES})