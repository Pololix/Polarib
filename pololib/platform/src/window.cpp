#include "platform/window.h"

#include <GLFW/glfw3.h>
#include "dbg/logger.h"

namespace plb
{
	Window::Window(WindowSpecs specs)
	{
		Logger& platformLogger = getLogger("platform");

		m_Window = glfwCreateWindow(specs.width, specs.height, specs.name, specs.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
		if (!m_Window)
		{
			platformLogger.log(LogLevel::Error, []() { return "Unable to create GLFW window"; });
			return;
		}
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
	}

	void Window::makeContextCurrent() const
	{
		glfwMakeContextCurrent(m_Window);
	}

	void Window::swapBuffers() const
	{
		glfwSwapBuffers(m_Window);
	}

	void Window::pollEvents() const
	{
		glfwPollEvents();
	}

	bool Window::shouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}
}