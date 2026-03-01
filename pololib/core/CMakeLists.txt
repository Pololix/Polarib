# core submodule
add_library(core STATIC
	src/application.cpp
 "src/events/event_system.cpp"
 "src/layers/layer_stack.cpp"
 
 "include/core/events/window_resize_event.h"  "include/core/events/window_close_event.h" "include/core/events/base_event.h" "include/core/events/events.h" "include/core/events/key_press_event.h" "include/core/events/key_release_event.h" "include/core/events/cursor_move_event.h" "include/core/events/click_down_event.h" "include/core/events/cursor_enter_event.h" "include/core/events/cursor_exit_event.h" "include/core/events/scroll_event.h" "include/core/events/click_release_event.h" "include/core/commands/base_command.h" "include/core/commands/logic_command.h" "include/core/commands/render_command.h" "include/core/commands/command_system.h" "src/commands/command_system.cpp" "include/core/graphics_context.h")

target_include_directories(core
	PUBLIC
		include
)

find_package(OpenGL REQUIRED)

target_link_libraries(core
	PUBLIC
		config	
		dbg
)