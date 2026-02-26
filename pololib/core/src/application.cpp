#include "core/application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "dbg/logger.h"

namespace plb
{
	Application::Application(AppSpecs specs)
	{
		Logger& logger = getLogger("core");

		if (!glfwInit())
		{	
			logger.log(LogLevel::Error, []() { return "Unable to init GLFW"; });
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef PLB_PLATFORM_MAC
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		m_Window.setPushEventCallback([this](Event&& e)
			{
				m_EventSystem.push(std::move(e));
			});
		m_Window.build(specs.windowSpecs);
		m_Window.makeContextCurrent();

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			logger.log(LogLevel::Error, []() { return "Unable to init GLAD"; });
			return;
		}

		glViewport(0, 0, specs.windowSpecs.width, specs.windowSpecs.height); // TODO: allow to resize windows -> WindowResizeEvent

		logger.log(LogLevel::Info, []() { return "App init correctly"; });
	}

	Application::~Application()
	{
		glfwTerminate();
	}

	void Application::run()
	{
		float currentTime;
		float pastTime = 0.0f;
		float deltaTime;

		while (!m_Window.shouldClose());
		{
			currentTime = glfwGetTime();
			deltaTime = currentTime - pastTime;
			pastTime = currentTime;

			m_EventSystem.flushEventBuffer(m_LayerStack);

			m_LayerStack.propagateUpdate(deltaTime);
			//m_CommandSystem.commit(); //logic cmds

			m_LayerStack.propagateRender();
			//m_CommandSystem.commit(); //render cmds

			m_Window.swapBuffers();
			m_Window.pollEvents();
		}
	}

	LayerID Application::addLayer(std::unique_ptr<Layer> layer)
	{
		return m_LayerStack.attachUnderlay(std::move(layer));
	}

	LayerID Application::addOverlay(std::unique_ptr<Layer> layer)
	{
		return m_LayerStack.attachOverlay(std::move(layer));
	}
}