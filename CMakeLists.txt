cmake_minimum_required(VERSION 3.26)

project(Pololib
	VERSION 0.1
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# config 
add_library(config INTERFACE)

target_compile_definitions(config
	INTERFACE
		 $<$<CONFIG:Debug>:VERSION_DEBUG>
) 

# modules
add_subdirectory(core)
add_subdirectory(dbg_utils)
add_subdirectory(graphics)
add_subdirectory(platform)
add_subdirectory(third_party)

# .lib 
add_library(pololib INTERFACE)

target_link_libraries(pololib
	INTERFACE
		core
		dbg_utils
		graphics
		platform
)

# test 
add_executable(app test/main.cpp)

target_link_libraries(app 
	PUBLIC
		pololib
)