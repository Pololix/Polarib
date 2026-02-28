#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class ClickReleaseEvent : public Event
	{
	public:
		const int m_Button;

		ClickReleaseEvent(int button)
			: m_Button(button) {}
			~ClickReleaseEvent() = default;

		virtual EventType getType() override { return EventType::ClickReleaseEvent; }
	};
}