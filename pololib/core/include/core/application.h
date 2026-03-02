#pragma once

#include <memory>
#include "core/window.h"
#include "core/layers/layer_stack.h"
#include "core/events/event_system.h"

namespace plb
{
	struct AppSpecs
	{
		WindowSpecs windowSpecs;
	};

	class Application
	{
	public:
		Application(std::unique_ptr<Window> window)
			: m_Window(std::move(window)) {}
		~Application() = default;

		LayerID addLayer(std::unique_ptr<Layer> layer);
		LayerID addOverlay(std::unique_ptr<Layer> layer);

		void suspendLayer(LayerID ID);
		void includeLayer(LayerID ID);
		void removeLayer(LayerID ID);

		void run();
	private:
		std::unique_ptr<Window> m_Window;

		LayerStack m_LayerStack;
		EventSystem m_EventSystem;
	};
}