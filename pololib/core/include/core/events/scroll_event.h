#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class ScrollEvent : public Event
	{
	public:
		ScrollEvent() = default;
		~ScrollEvent() = default;

		virtual EventType getType() override { return EventType::ScrollEvent; }
	};
}