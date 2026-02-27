#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class CursorExitEvent : public Event
	{
	public:
		CursorExitEvent() = default;
		~CursorExitEvent() = default;

		virtual EventType getType() override { return EventType::CursorExitEvent; }
	};
}