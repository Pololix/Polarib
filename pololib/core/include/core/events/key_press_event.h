#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class KeyPressEvent : public Event
	{
	public:
		KeyPressEvent() = default;
		~KeyPressEvent() = default;

		virtual EventType getType() override { return EventType::KeyPressEvent; }
	};
}