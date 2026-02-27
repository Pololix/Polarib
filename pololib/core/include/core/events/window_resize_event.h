#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent() = default;
		~WindowResizeEvent() = default;

		virtual EventType getType() override { return EventType::WindowResizeEvent; }
	};
}