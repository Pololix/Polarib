#include "core/events/event_system.h"

#include "core/events/layer_stack.h"

namespace plb
{
	void EventSystem::push(std::unique_ptr<Event> e)
	{
		m_EventBuffer.push_back(std::move(e));
	}

	void EventSystem::flushEventBuffer(LayerStack& layerStack)
	{
		for (auto& ptr : m_EventBuffer)
		{
			layerStack.propagateEvent(*ptr.get());
		}

		m_EventBuffer.clear();
	}
}