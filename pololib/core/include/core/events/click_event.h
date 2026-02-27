#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class ClickEvent : public Event
	{
	public:
		ClickEvent() = default;
		~ClickEvent() = default;

		virtual EventType getType() override { return EventType::ClickEvent; }
	};
}