# core submodule
add_library(core STATIC
	src/application.cpp
  "include/core/events/layer.h" "include/core/events/layer_stack.h" "src/events/layer_stack.cpp" "include/core/events/event.h"   "include/core/events/event_system.h" "src/events/event_system.cpp" "include/core/commands/command_system.h" "src/events/layer.cpp")

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