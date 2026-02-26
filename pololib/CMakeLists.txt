# pololib specific
# config 
add_library(config INTERFACE)

target_compile_definitions(config
	INTERFACE
		# platform
		$<$<PLATFORM_ID:Linux>:PLB_PLATFORM_LNX>
		$<$<PLATFORM_ID:Windows>:PLB_PLATFORM_WND>
		$<$<PLATFORM_ID:Darwin>:PLB_PLATFORM_MAC>
		# build
		$<$<CONFIG:Debug>:PLB_BUILD_DEBUG>
		$<$<CONFIG:Release>:PLB_BUILD_RELEASE>
) 

# submodules
add_subdirectory(core)
add_subdirectory(dbg)
add_subdirectory(deps)

# .lib
add_library(pololib INTERFACE)
target_link_libraries(pololib
	INTERFACE
		core
		dbg
		platform
)