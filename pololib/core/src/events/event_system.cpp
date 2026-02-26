#include "core/events/event_system.h"

#include "core/events/layer_stack.h"

namespace plb
{
	void EventSystem::push(Event&& e)
	{
		m_EventBuffer.push_back(std::move(e));
	}

	void EventSystem::flushEventBuffer(LayerStack& layerStack)
	{
		for (auto& e : m_EventBuffer)
		{
			layerStack.propagateEvent(e);
		}

		m_EventBuffer.clear();
	}
}