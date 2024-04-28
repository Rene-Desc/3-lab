cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME Third_lab)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")

add_executable("${PROJECT_NAME}" third-lab.cpp
	class_string.cpp
	class_string.hpp
)
