# PLB_TODO: vendoring -> pckg (conan)

# - OpenGL
find_package(OpenGL REQUIRED)

# - glad
add_library(glad STATIC
	glad/src/glad.c
)

target_include_directories(glad 
	PUBLIC
		glad/include
)

# - glfw
add_subdirectory(glfw)

# - glm
add_library(glm INTERFACE)

target_include_directories(glm 
	INTERFACE
		glm
)

# - imgui
add_library(imgui STATIC
	imgui/imgui.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_tables.cpp
	imgui/imgui_widgets.cpp
	imgui/backends/imgui_impl_glfw.cpp
	imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui
	PUBLIC 
		imgui
		imgui/backends
)

target_link_libraries(imgui
	PUBLIC
		glfw
		OpenGL::GL
)