include(FindPkgConfig)
cmake_minimum_required(VERSION 3.13)
project(Octo)


# =================================================================
# External libraries

# Python Lib
find_package(Python 3.8 COMPONENTS Interpreter Development REQUIRED)

# Capstone Lib
pkg_check_modules(Capstone REQUIRED Capstone)
# =================================================================


# =================================================================
# Internal libraries

# sources
file(GLOB SRC_IO ./io/*.c)
file(GLOB SRC_CLI ./cli/*.c)
file(GLOB SRC_ARCH ./arch/*.c)

# objects
add_library(cli OBJECT ${SRC_CLI})
add_library(io OBJECT ${SRC_IO})
add_library(arch OBJECT ${SRC_ARCH})
target_link_libraries(io PUBLIC ${Capstone_LINK_LIBRARIES})
# =================================================================


# =================================================================
# Executables

# sources
add_executable(octo octo.c)
add_executable(test test.c)

# includes
target_include_directories(cli PUBLIC ./)
target_include_directories(io PUBLIC ./ ${Capstone_INCLUDE_DIRS})
target_include_directories(octo PUBLIC ./)
target_include_directories(test PUBLIC ${Python_INCLUDE_DIRS})

# link
target_link_libraries(test Python::Python)
target_link_libraries(octo cli io)
# =================================================================


# =================================================================
# Compile options
target_compile_options(cli PRIVATE -Werror -Wall -Wextra)
target_compile_options(io PRIVATE -Werror -Wall -Wextra)
target_compile_options(octo PRIVATE -Werror -Wall -Wextra)
# =================================================================
