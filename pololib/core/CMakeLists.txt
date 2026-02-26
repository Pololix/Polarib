# core submodule
add_library(core STATIC
	src/application.cpp
 "src/events/event_system.cpp")

target_include_directories(core
	PUBLIC
		include
)

target_link_libraries(core
	PUBLIC
		glad
		glfw
		config	
		dbg
)