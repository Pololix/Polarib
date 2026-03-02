#include "platform/glfw/window_glfw.h"

#include "graphics/opengl/opengl_context.h"
#include <glfw/glfw3.h>
#include "core/events/events.h"

namespace plb
{
	WindowGLFW::WindowGLFW()
	{
		if (!glfwInit())
		{
			return; //PLB_TODO: log status
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // PLB_TODO: chage versions and profiles for macros

#ifdef PLB_PLATFORM_MAC
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
		//PLB_FORNOW:
		m_Context = std::make_unique<OpenGLContext>();
	}

	void WindowGLFW::build(WindowSpecs specs)
	{
		if (!m_PushEvent)
		{
			/*Logger& logger = getLogger("glfw window"); PLB_TODO: log
			logger.log(LogLevel::Error, []() { return "Unable to build GLFW window without a pushEventCallback fn"; });*/
		}

		m_Window = glfwCreateWindow(specs.width, specs.height, specs.name, specs.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
		if (!m_Window)
		{
			/*Logger& logger = getLogger("glfw window"); PLB_TODO: log
			logger.log(LogLevel::Error, []() { return "Unable to build GLFW window"; });*/
			return;
		}

		makeContextCurrent();

		m_Context->init();

		glfwSetWindowUserPointer(m_Window, this);

		glfwSetFramebufferSizeCallback(m_Window, framebufferCallback);
		glfwSetKeyCallback(m_Window, keyCallback);
		glfwSetCursorPosCallback(m_Window, cursorPosCallback);
		glfwSetCursorEnterCallback(m_Window, cursorEnterCallback);
		glfwSetMouseButtonCallback(m_Window, mouseButtonCallback);
		glfwSetScrollCallback(m_Window, scrollCallback);
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

	void WindowGLFW::framebufferCallback(GLFWwindow* window, int width, int height)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			/*Logger& logger = getLogger("glfw window"); PLB_TODO: log
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });*/
			return;
		}

		//win->m_PushEvent(std::make_unique<WindowResizeEvent>(deltaWidth, deltaHeight));
	}

	void WindowGLFW::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			/*Logger& logger = getLogger("glfw window"); PLB_TODO: log
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });*/
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

	void WindowGLFW::cursorPosCallback(GLFWwindow* window, double xPos, double yPos)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			/*Logger& logger = getLogger("glfw window"); PLB_TODO: log
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });*/
			return;
		}

		//win->m_PushEvent(std::make_unique<CursorMoveEvent>(deltaX, deltaY));
	}

	void WindowGLFW::cursorEnterCallback(GLFWwindow* window, int entered)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			//Logger& logger = getLogger("glfw window"); PLB_TODO: log
			//logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });
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

	void WindowGLFW::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			/*Logger& logger = getLogger("glfw window"); PLB_TODO: log
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });*/
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

	void WindowGLFW::scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
	{
		WindowGLFW* win = (WindowGLFW*)glfwGetWindowUserPointer(window);

		if (!win)
		{
			/*Logger& logger = getLogger("glfw window"); PLB_TODO: log
			logger.log(LogLevel::Error, []() { return "Unable to retrieve glfwWindowUserPointer"; });*/
			return;
		}

		//win->m_PushEvent(std::make_unique<ScrollEvent>((float)xOffset, (float)yOffset));
	}
}