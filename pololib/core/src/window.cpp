#include "platform/window.h"

#include <GLFW/glfw3.h>
#include "dbg/logger.h"

namespace plb
{
	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
	}

	void Window::build(WindowSpecs specs)
	{
		Logger& logger = getLogger("platform");

		m_Window = glfwCreateWindow(specs.width, specs.height, specs.name, specs.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
		if (!m_Window)
		{
			logger.log(LogLevel::Error, []() { return "Unable to build GLFW window"; });
			return;
		}

		// set call backs
	}

	void Window::setPushEventCallback(std::function<void(Event&& event)> pushEventCallback)
	{
		m_PushEventCallback = pushEventCallback;
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