# core submodule
add_library(core STATIC
	src/application.cpp
 "include/core/event.h" "include/core/event_dispatcher.h")

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
)