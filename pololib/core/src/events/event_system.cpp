#include "core/events/event_system.h"

namespace plb
{
	void EventSystem::push(std::unique_ptr<Event> event)
	{
		m_EventBuffer.push_back(std::move(event));
	}

	std::vector<std::unique_ptr<Event>>& EventSystem::getBuffer()
	{
		return m_EventBuffer;
	}

	void EventSystem::clearBuffer()
	{
		m_EventBuffer.clear();
	}
}