#pragma once

#include <vector>
#include "core/events/event.h"

namespace plb
{
	class EventSystem
	{
	public:
		EventSystem() = default;
		~EventSystem() = default;

		void push(Event&& e);
		void flushEventBuffer(LayerStack& layerStack);
	private:
		std::vector<Event> m_EventBuffer;
	};
}