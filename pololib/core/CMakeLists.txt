# core submodule
add_library(core STATIC
	src/application.cpp
)

target_include_directories(core
	PUBLIC
		include
)

target_link_libraries(core
	PUBLIC
		glad
		glfw
		config
		platform	
		dbg
)