#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class CursorEnterEvent : public Event
	{
	public:
		CursorEnterEvent() = default;
		~CursorEnterEvent() = default;

		virtual EventType getType() override { return EventType::CursorEnterEvent; }
	};
}