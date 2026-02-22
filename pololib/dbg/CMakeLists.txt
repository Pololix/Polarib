# dbg utils
add_library(dbg INTERFACE)

target_include_directories(dbg
	INTERFACE	
		include
)

target_link_libraries(dbg
	INTERFACE
		config
)