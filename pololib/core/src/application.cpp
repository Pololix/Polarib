#include "core/application.h"

#include "dbg/logger.h"
#include "dbg/assert.h"

namespace plb
{
	Application::Application(AppSpecs specs)
	{
		// PLB_TODO: decide what window and api based on specs

		Logger& logger = getLogger("core");
		logger.log(LogLevel::Info, []() { return "App init correctly"; });
	}

	void Application::run()
	{
		float currentTime;
		float pastTime = 0.0f;
		float deltaTime;

		while (!m_Window->shouldClose())
		{
			currentTime = m_Window->getTime();
			deltaTime = currentTime - pastTime;
			pastTime = currentTime;

			m_Window->pollEvents();
			m_EventSystem.flushEventBuffer(m_LayerStack);

			m_LayerStack.propagateUpdate(deltaTime);
			m_CommandSystem.flushCommandBuffer(); //logic cmds

			//renderer.render() -> emmit render cmds
			m_CommandSystem.flushCommandBuffer(); //render cmds

			m_Window->swapBuffers();
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