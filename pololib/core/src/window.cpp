#include "core/window.h"

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
		m_Width = specs.width;
		m_Height = specs.height;

		m_Window = glfwCreateWindow(specs.width, specs.height, specs.name, specs.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
		if (!m_Window)
		{
			Logger& logger = getLogger("window");
			logger.log(LogLevel::Error, []() { return "Unable to build GLFW window"; });
			return;
		}

		glfwSetWindowUserPointer(m_Window, this);

		// set call backs
		glfwSetFramebufferSizeCallback(m_Window, framebufferCallback);
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

	void Window::framebufferCallback(GLFWwindow* window, int width, int height)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		m_Width = width;
		m_Height = height;

		WindowResizeEvent e;
		m_PushEventCallback(std::move(e));
	}
}