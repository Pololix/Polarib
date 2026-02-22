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