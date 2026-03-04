# platform submodule
add_library(platform STATIC
	src/glfw/window_glfw.cpp
 "include/platform/glfw/glfw_config.h")

target_include_directories(platform
	PUBLIC
		include
)

target_link_libraries(platform
	PRIVATE
		core
		glfw
		dbg
		config
		graphics
)