include(FindPkgConfig)
cmake_minimum_required(VERSION 3.13)
project(Octo)


# =================================================================
# External libraries

# Python Lib
find_package(Python 3.8 COMPONENTS Interpreter Development REQUIRED)

# capstone Lib
pkg_check_modules(capstone REQUIRED capstone)
# =================================================================


# =================================================================
# Internal libraries

# sources
file(GLOB SRC_IO ./io/*.c)
file(GLOB SRC_CLI ./cli/*.c)
file(GLOB SRC_CORE ./core/*.c)

# objects
add_library(cli OBJECT ${SRC_CLI})
add_library(io OBJECT ${SRC_IO})
add_library(core OBJECT ${SRC_CORE})
target_link_libraries(io PUBLIC ${capstone_LINK_LIBRARIES})
# =================================================================


# =================================================================
# Executables

# sources
add_executable(octo octo.c)

# includes
target_include_directories(cli PUBLIC ./)
target_include_directories(core PUBLIC ./ ${capstone_INCLUDE_DIRS} ${Python_INCLUDE_DIRS})
target_include_directories(io PUBLIC ./)
target_include_directories(octo PUBLIC ./)

# link
target_link_libraries(octo cli io core Python::Python)
# =================================================================


# =================================================================
# Compile options
target_compile_options(cli PRIVATE -Werror -Wall -Wextra)
target_compile_options(io PRIVATE -Werror -Wall -Wextra)
target_compile_options(core PRIVATE -Werror -Wall -Wextra)
target_compile_options(octo PRIVATE -Werror -Wall -Wextra)
# =================================================================
