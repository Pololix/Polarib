#include "core/events/event_system.h"

#include "core/layers/layer_stack.h"

namespace plb
{
	void EventSystem::push(std::unique_ptr<Event> e)
	{
		m_EventBuffer.push_back(std::move(e));
	}

	void EventSystem::flush(LayerStack& stack)
	{
		for (auto& e : m_EventBuffer)
		{
			stack.propagateEvent(*e);
			if (e.m_Handled) break;
		}

		m_EventBuffer.clear();
	}
}