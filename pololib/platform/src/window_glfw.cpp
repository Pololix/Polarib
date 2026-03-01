#include "platform/window_glfw.h"

#include <GLFW/glfw3.h>
#include "core/events/events.h"
#include "dbg/logger.h"

namespace plb
{
	WindowGLFW::WindowGLFW()
	{
		if (!m_HasInit)
		{
			Logger& logger = getLogger("glfw window");

			if (!glfwInit())
			{
				logger.log(LogLevel::Error, []() { return "Unable to init GLFW"; });
				return;
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); 
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // PLB_TODO: chage versions and profiles for macros

#ifdef PLB_PLATFORM_MAC
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
			m_HasInit = true;
		}
	}

	WindowGLFW::~WindowGLFW()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowGLFW::build(WindowSpecs specs)
	{
		if (!m_PushEvent)
		{
			Logger& logger = getLogger("glfw window");
			logger.log(LogLevel::Error, []() { return "Unable to build GLFW window without a pushEventCallback fn"; });
		}

		m_Width = specs.width;
		m_Height = specs.height;

		m_Window = glfwCreateWindow(specs.width, specs.height, specs.name, specs.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
		if (!m_Window)
		{
			Logger& logger = getLogger("glfw window");
			logger.log(LogLevel::Error, []() { return "Unable to build GLFW window"; });
			return;
		}

		glfwMakeContextCurrent(m_Window);

		glfwSetWindowUserPointer(m_Window, this);

		glfwSetFramebufferSizeCallback(m_Window, framebufferCallback);
		glfwSetKeyCallback(m_Window, keyCallback);
		glfwSetCursorPosCallback(m_Window, cursorPosCallback);
		glfwSetCursorEnterCallback(m_Window, cursorEnterCallback);
		glfwSetMouseButtonCallback(m_Window, mouseButtonCallback);
		glfwSetScrollCallback(m_Window, scrollCallback);
	}

	void WindowGLFW::pollEvents() const
	{
		glfwPollEvents();
	}

	void WindowGLFW::swapBuffers() const
	{
		glfwSwapBuffers(m_Window);
	}

	bool WindowGLFW::shouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void WindowGLFW::framebufferCallback(GLFWwindow* window, int width, int height)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("glfw window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		int deltaWidth = width - win->m_Width;
		int deltaHeight = height - win->m_Height;

		win->m_Width = width;
		win->m_Height = height;

		win->m_PushEvent(std::make_unique<WindowResizeEvent>(deltaWidth, deltaHeight));
	}

	void WindowGLFW::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("glfw window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		switch (action)
		{
		case GLFW_PRESS:
		{
			win->m_PushEvent(std::make_unique<KeyPressEvent>(key, mods));
			break;
		}
		case GLFW_RELEASE:
		{
			win->m_PushEvent(std::make_unique<KeyReleaseEvent>(key));
			break;
		}
		case GLFW_REPEAT:
		{
			//win->m_PushEvent(std::make_unique<KeyPressEvent>());
			break;
		}
		}
	}

	void WindowGLFW::cursorPosCallback(GLFWwindow* window, double xPos, double yPos)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("glfw window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		static float xPrev;
		static float yPrev;

		float deltaX = (float)xPos - xPrev;
		float deltaY = (float)yPos - yPrev;

		xPrev = xPos;
		yPrev = yPos;


		win->m_PushEvent(std::make_unique<CursorMoveEvent>(deltaX, deltaY));
	}

	void WindowGLFW::cursorEnterCallback(GLFWwindow* window, int entered)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("glfw window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		if (entered)
		{
			win->m_PushEvent(std::make_unique<CursorEnterEvent>());
		}
		else
		{
			win->m_PushEvent(std::make_unique<CursorExitEvent>());
		}
	}

	void WindowGLFW::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("glfw window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		if (action == GLFW_PRESS)
		{
			win->m_PushEvent(std::make_unique<ClickDownEvent>(button, mods));
		}
		else
		{
			win->m_PushEvent(std::make_unique<ClickReleaseEvent>(button));
		}
	}

	void WindowGLFW::scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			Logger& logger = getLogger("glfw window");
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
			return;
		}

		win->m_PushEvent(std::make_unique<ScrollEvent>((float)xOffset, (float)yOffset));
	}
}