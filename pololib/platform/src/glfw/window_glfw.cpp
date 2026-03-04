#include "platform/glfw/window_glfw.h"

#include "graphics/opengl/opengl_context.h"
#include <glfw/glfw3.h>
#include "core/events/events.h"
#include "dbg/logs.h"
#include "dbg/assertions.h"
#include "platform/glfw/glfw_config.h"

namespace plb
{
	WindowGLFW::WindowGLFW()
	{
		PLB_ASSERT(glfwInit(), "Unable to init GLFW");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, PLB_GLFW_MAJOR_VERSION);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, PLB_GLFW_MINOR_VERSION);
		glfwWindowHint(GLFW_OPENGL_PROFILE, PLB_GLFW_PROFILE);

#ifdef PLB_PLATFORM_MAC
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
		//PLB_FORNOW:
		m_Context = std::make_unique<OpenGLContext>();
	}

	void WindowGLFW::build(WindowSpecs specs)
	{
		PLB_ASSERT(m_PushEvent, "Tried to build a window without an event callback");

		m_Window = glfwCreateWindow(specs.width, specs.height, specs.name, specs.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
		PLB_ASSERT(m_Window, "Failed to create a GLFW window");

		makeContextCurrent();

		m_Context->init();

		glfwSetWindowUserPointer(m_Window, this);

		// window events
		glfwSetWindowCloseCallback(m_Window, closeCallback);
		glfwSetFramebufferSizeCallback(m_Window, framebufferSizeCallback);

		// cursor inputs
		glfwSetCursorEnterCallback(m_Window, cursorEnterCallback);
		glfwSetCursorPosCallback(m_Window, cursorPosCallback);
		glfwSetScrollCallback(m_Window, scrollCallback);

		// mouse inputs
		glfwSetMouseButtonCallback(m_Window, mouseButtonCallback);

		// key inputs
		glfwSetKeyCallback(m_Window, keyCallback);
	}

	void WindowGLFW::makeContextCurrent()
	{
		glfwMakeContextCurrent(m_Window);
	}

	void WindowGLFW::pollEvents()
	{
		glfwPollEvents();
	}

	void WindowGLFW::swapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}

	float WindowGLFW::getTime() 
	{
		return glfwGetTime();
	}

	// window events
	void WindowGLFW::closeCallback(GLFWwindow* window)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);
		if (!win) 
		{
			PLB_LOG_ERROR("window", "Unable to retrieve the user pointer from a GLFW window");
			return;
		}
	}

	void WindowGLFW::framebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);
		if (!win)
		{
			PLB_LOG_ERROR("window", "Unable to retrieve the user pointer from a GLFW window");
			return;
		}

		//win->m_PushEvent(std::make_unique<WindowResizeEvent>(deltaWidth, deltaHeight));
	}

	// cursor inputs
	void WindowGLFW::cursorEnterCallback(GLFWwindow* window, int entered)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);
		if (!win)
		{
			PLB_LOG_ERROR("window", "Unable to retrieve the user pointer from a GLFW window");
			return;
		}

		if (entered)
		{
			//win->m_PushEvent(std::make_unique<CursorEnterEvent>());
		}
		else
		{
			//win->m_PushEvent(std::make_unique<CursorExitEvent>());
		}
	}

	void WindowGLFW::cursorPosCallback(GLFWwindow* window, double xPos, double yPos)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);
		if (!win)
		{
			PLB_LOG_ERROR("window", "Unable to retrieve the user pointer from a GLFW window");
			return;
		}

		//win->m_PushEvent(std::make_unique<CursorMoveEvent>(deltaX, deltaY));
	}

	void WindowGLFW::scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);
		if (!win)
		{
			PLB_LOG_ERROR("window", "Unable to retrieve the user pointer from a GLFW window");
			return;
		}

		//win->m_PushEvent(std::make_unique<ScrollEvent>((float)xOffset, (float)yOffset));
	}

	// mouse inputs
	void WindowGLFW::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);
		if (!win)
		{
			PLB_LOG_ERROR("window", "Unable to retrieve the user pointer from a GLFW window");
			return;
		}

		if (action == GLFW_PRESS)
		{
			//win->m_PushEvent(std::make_unique<ClickDownEvent>(button, mods));
		}
		else
		{
			//win->m_PushEvent(std::make_unique<ClickReleaseEvent>(button));
		}
	}

	// key inputs
	void WindowGLFW::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);
		if (!win)
		{
			PLB_LOG_ERROR("window", "Unable to retrieve the user pointer from a GLFW window");
			return;
		}

		switch (action)
		{
		case GLFW_PRESS:
		{
			//win->m_PushEvent(std::make_unique<KeyPressEvent>(key, mods));
			break;
		}
		case GLFW_RELEASE:
		{
			//win->m_PushEvent(std::make_unique<KeyReleaseEvent>(key));
			break;
		}
		case GLFW_REPEAT:
		{
			//win->m_PushEvent(std::make_unique<KeyPressEvent>());
			break;
		}
		}
	}
}