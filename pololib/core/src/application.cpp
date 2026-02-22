#include "core/application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "platform/window.h"
#include "dbg/logger.h"

namespace plb
{
	Application::Application(AppSpecs specs)
	{
		Logger& coreLogger = getLogger("core");

		if (!glfwInit())
		{	
			coreLogger.log(LogLevel::Error, []() { return "Unable to init GLFW"; });
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
			coreLogger.log(LogLevel::Error, []() { return "Unable to init GLAD"; });
			return;
		}

		// FOR NOW
		glViewport(0, 0, specs.windowSpecs.width, specs.windowSpecs.height); // TODO: allow to resize windows

		coreLogger.log(LogLevel::Info, []() { return "App init correctly"; });
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