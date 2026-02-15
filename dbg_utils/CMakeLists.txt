add_library(dbg_utils INTERFACE)

target_include_directories(dbg_utils
	INTERFACE
		include
)

target_link_libraries(dbg_utils
	INTERFACE
		config
)