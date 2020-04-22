cmake_minimum_required(VERSION 3.1)

project(Octo)

# LIBRARIES
add_library(cli OBJECT ./cli/cli.c)
add_library(io OBJECT ./io/io.c)

# EXECUTABLE
add_executable(octo
  $<TARGET_OBJECTS:cli>
  octo.c)

target_include_directories(octo PUBLIC ./)