# dbg utils
add_library(dbg STATIC
	src/logger.cpp
)

target_include_directories(dbg
	PUBLIC	
		include
)

target_link_libraries(dbg
	PRIVATE
		config
)