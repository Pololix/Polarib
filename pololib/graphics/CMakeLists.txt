# graphics submodule
add_library(graphics STATIC
	src/opengl_context.cpp
)

target_include_directories(graphics
	PUBLIC
		include
)

find_package(OpenGL REQUIRED)

target_link_libraries(graphics
	PRIVATE
		core
		glad
		OpenGL::GL
		dbg
		config
)