# core submodule
add_library(core STATIC
	src/application.cpp
 "include/core/config.h"   )

target_include_directories(core
	PUBLIC
		include
)

target_link_libraries(core
	PRIVATE
		config	
		dbg
)