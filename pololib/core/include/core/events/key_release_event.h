#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class KeyReleaseEvent : public Event
	{
	public:
		const int m_Key;

		KeyReleaseEvent(int key) 
			: m_Key(key) {}
		~KeyReleaseEvent() = default;

		virtual EventType getType() override { return EventType::KeyReleaseEvent; }
	};
}