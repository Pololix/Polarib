add_library(platform STATIC
	src/window.cpp
)

target_include_directories(platform
	PUBLIC
		include
)

target_link_libraries(platform
	PUBLIC
		glad
		glfw
		dbg_utils
)