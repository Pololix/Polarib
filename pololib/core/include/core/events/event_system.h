#pragma once

#include <vector>
#include <memory>
#include "core/events/base_event.h"

namespace plb
{
	class LayerStack;

	class EventSystem
	{
	public:
		EventSystem() = default;
		~EventSystem() = default;

		void push(std::unique_ptr<Event> e);
		void flushEventBuffer(LayerStack& layerStack);
	private:
		std::vector<std::unique_ptr<Event>> m_EventBuffer;
	};
}