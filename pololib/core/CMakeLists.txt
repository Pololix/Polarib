# core submodule
add_library(core STATIC
	src/application.cpp
 "src/events/event_system.cpp"
 "src/events/layer_stack.cpp"
 "src/window.cpp"
 "include/core/events/window_resize_event.h"  "include/core/events/window_close_event.h" "include/core/events/base_event.h" "include/core/events/events.h" "include/core/events/key_press_event.h" "include/core/events/key_release_event.h" "include/core/events/cursor_move_event.h" "include/core/events/click_event.h" "include/core/events/cursor_enter_event.h" "include/core/events/cursor_exit_event.h" "include/core/events/scroll_event.h")

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