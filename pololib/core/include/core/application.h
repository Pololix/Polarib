#pragma once

#include "core/window.h"
#include "core/layers/layer_stack.h"
#include "core/events/event_system.h"
#include "core/commands/command_system.h"

namespace plb
{
	struct AppSpecs
	{
		WindowSpecs windowSpecs;
		int windowSystem;
		int graphicsAPI;
	};

	class Application
	{
	public:
		Application(AppSpecs specs);
		~Application() = default;

		void run();

		LayerID addLayer(std::unique_ptr<Layer> layer);
		LayerID addOverlay(std::unique_ptr<Layer> layer);
	private:
		std::unique_ptr<Window> m_Window = nullptr;
		LayerStack m_LayerStack;

		EventSystem m_EventSystem;
		CommandSystem m_CommandSystem;
	};
}