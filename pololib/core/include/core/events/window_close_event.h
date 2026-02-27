#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;
		~WindowCloseEvent() = default;

		virtual EventType getType() override { return EventType::WindowCloseEvent; }
	};
}