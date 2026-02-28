#pragma once

#include "core/events/event_system.h"
#include "core/layers/layer_stack.h"
#include "core/window.h"

namespace plb
{
	struct AppSpecs
	{
		 WindowSpecs windowSpecs;
	};

	class Application
	{
	public:
		Application(AppSpecs specs);
		~Application();

		void run();

		LayerID addLayer(std::unique_ptr<Layer> layer);
		LayerID addOverlay(std::unique_ptr<Layer> layer);
	private:
		Window m_Window;
		LayerStack m_LayerStack;
		EventSystem m_EventSystem;
	};
}