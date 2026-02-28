#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class ScrollEvent : public Event
	{
	public:
		const float m_OffsetX;
		const float m_OffsetY;

		ScrollEvent(float offX, float offY)
			: m_OffsetX(offX), m_OffsetY(offY) {}
		~ScrollEvent() = default;

		virtual EventType getType() override { return EventType::ScrollEvent; }
	};
}