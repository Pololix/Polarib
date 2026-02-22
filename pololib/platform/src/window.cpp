#include "platform/window.h"

#include <GLFW/glfw3.h>
#include "dbg/logger.h"

namespace plb
{
	Window::Window(WindowSpecs specs)
	{
		Logger& platformLogger = getLogger("platform");

		m_window = glfwCreateWindow(specs.width, specs.height, specs.name, specs.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
		if (!m_window)
		{
			platformLogger.log(LogLevel::Error, []() { return "Unable to create GLFW window"; });
			return;
		}
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_window);
	}

	void Window::makeContextCurrent() const
	{
		glfwMakeContextCurrent(m_window);
	}

	void Window::swapBuffers() const
	{
		glfwSwapBuffers(m_window);
	}

	void Window::pollEvents() const
	{
		glfwPollEvents();
	}

	bool Window::shouldClose() const
	{
		return glfwWindowShouldClose(m_window);
	}
}