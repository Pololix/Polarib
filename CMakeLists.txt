cmake_minimum_required(VERSION 3.26)

project(Pololib
	VERSION 0.1
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# modules
add_subdirectory(core)
add_subdirectory(dbg_utils)
add_subdirectory(graphics)
add_subdirectory(third_party)

# executable TODO: change to .lib output
add_executable(APP test/main.cpp)

target_link_libraries(APP
	PUBLIC
		core
		dbg_utils
		graphics
)