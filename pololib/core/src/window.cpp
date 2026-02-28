#include "core/window.h"

#include <GLFW/glfw3.h>
#include "core/events/events.h"
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

		glfwSetFramebufferSizeCallback(m_Window, framebufferCallback);
		glfwSetKeyCallback(m_Window, keyCallback);
		glfwSetCursorPosCallback(m_Window, cursorPosCallback);
		glfwSetCursorEnterCallback(m_Window, cursorEnterCallback);
		glfwSetMouseButtonCallback(m_Window, mouseButtonCallback);
		glfwSetScrollCallback(m_Window, scrollCallback);
	}

	void Window::setPushEventCallback(std::function<void(std::unique_ptr<Event> e)> fn)
	{
		m_PushEventCallback = fn;
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

		int deltaWidth = win->m_Width - width;
		int deltaHeight = win->m_Height - height;

		win->m_Width = width;
		win->m_Height = height;

		win->m_PushEventCallback(std::make_unique<WindowResizeEvent>(deltaWidth, deltaHeight));
	}

	void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		switch (action)
		{
			case GLFW_PRESS:
			{
				win->m_PushEventCallback(std::make_unique<KeyPressEvent>(key, mods));
				break;
			}
			case GLFW_RELEASE:
			{
				win->m_PushEventCallback(std::make_unique<KeyReleaseEvent>(key));
				break;
			}
			case GLFW_REPEAT:
			{
				//win->m_PushEventCallback(std::make_unique<KeyPressEvent>());
				break;
			}
		}
	}

	void Window::cursorPosCallback(GLFWwindow* window, double xPos, double yPos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		static float xPrev;
		static float yPrev;

		float deltaX = xPrev - (float)xPos;
		float deltaY = yPrev - (float)yPos;

		xPrev = xPos;
		yPrev = yPos;


		win->m_PushEventCallback(std::make_unique<CursorMoveEvent>(deltaX, deltaY));
	}

	void Window::cursorEnterCallback(GLFWwindow* window, int entered)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		if (entered)
		{
			win->m_PushEventCallback(std::make_unique<CursorEnterEvent>());
		}
		else
		{
			win->m_PushEventCallback(std::make_unique<CursorExitEvent>());
		}
	}

	void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		if (action == GLFW_PRESS)
		{
			win->m_PushEventCallback(std::make_unique<ClickDownEvent>(button, mods));
		}
		else
		{
			win->m_PushEventCallback(std::make_unique<ClickReleaseEvent>(button));
		}
	}

	void Window::scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		win->m_PushEventCallback(std::make_unique<ScrollEvent>((float)xOffset, (float)yOffset));
	}
}