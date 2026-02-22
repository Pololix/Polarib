#include "core/application.h"

#include <iostream> //TODO: remove io from app -> logging
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "platform/window.h"

namespace plb
{
	Application::Application(AppSpecs specs)
	{
		if (!glfwInit())
		{	
			std::cout << "Unable to init GLFW\n";
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef PLB_PLATFORM_MAC
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		m_window = std::make_unique<Window>(specs.windowSpecs);
		m_window.get()->makeContextCurrent();

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Unable to init GLAD\n";
			return;
		}

		// FOR NOW
		glViewport(0, 0, specs.windowSpecs.width, specs.windowSpecs.height); // TODO: allow to resize windows

		std::cout << "App init correctly\n";
	}

	Application::~Application()
	{
		glfwTerminate();
	}

	void Application::run()
	{
		/*float currentTime;
		float pastTime = 0.0f;
		float deltaTime = 0.0f;*/

		do
		{
			/*currentTime = glfwGetTime();
			deltaTime = currentTime - pastTime;
			pastTime = currentTime;*/

			m_window.get()->swapBuffers();
			m_window.get()->pollEvents();
		} while (!m_window.get()->shouldClose());
	}
}