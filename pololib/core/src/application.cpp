#include "core/application.h"

namespace plb
{
	LayerID Application::addLayer(std::unique_ptr<Layer> layer)
	{
		return m_LayerStack.attachLayer(std::move(layer), false);
	}

	LayerID Application::addOverlay(std::unique_ptr<Layer> layer)
	{
		return m_LayerStack.attachLayer(std::move(layer), true);
	}

	void Application::suspendLayer(LayerID ID)
	{
		m_LayerStack.suspendLayer(ID);
	}

	void Application::includeLayer(LayerID ID)
	{
		m_LayerStack.includeLayer(ID);
	}

	void Application::removeLayer(LayerID ID)
	{
		m_LayerStack.detachLayer(ID);
	}

	void Application::run()
	{
		float currentTime = 0, pastTime = 0, deltaTime = 0;

		while (true) //PLB_TODO: add smart termination
		{
			currentTime = m_Window->getTime();
			deltaTime = currentTime - pastTime;
			pastTime = currentTime;

			m_Window->pollEvents();
			m_EventSystem.flush(m_LayerStack);

			m_LayerStack.update(deltaTime);
			//m_CommandSystem.commit();

			//m_Renderer.beginNewFrame(); //PLB_TODO: integrate imgui to the cycle
			m_LayerStack.render();
			//m_Renderer.commit();
			//m_Renderer.endFrame();

			m_Window->swapBuffers();
		}
	}
}