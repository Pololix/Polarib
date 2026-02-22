#include "platform/window.h"

#include <GLFW/glfw3.h>

#include <iostream> // TODO: remove io from window -> logger

namespace plb
{
	Window::Window(WindowSpecs specs)
	{
		m_window = glfwCreateWindow(specs.width, specs.height, specs.name, specs.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
		if (!m_window)
		{
			std::cout << "Unable to create GLFW window\n";
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