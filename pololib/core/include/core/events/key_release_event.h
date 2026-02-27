#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class KeyReleaseEvent : public Event
	{
	public:
		KeyReleaseEvent() = default;
		~KeyReleaseEvent() = default;

		virtual EventType getType() override { return EventType::KeyReleaseEvent; }
	};
}