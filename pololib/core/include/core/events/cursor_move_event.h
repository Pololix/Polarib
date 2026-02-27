#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class CursorMoveEvent : public Event
	{
	public:
		CursorMoveEvent() = default;
		~CursorMoveEvent() = default;

		virtual EventType getType() override { return EventType::CursorMoveEvent; }
	};
}