# root dir
cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Pololib
	VERSION 0.1
	LANGUAGES C CXX
)

add_subdirectory(pololib)
add_subdirectory(apps)
