#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class CursorMoveEvent : public Event
	{
	public:
		const float m_DeltaX;
		const float m_DeltaY;

		CursorMoveEvent(float dx, float dy)
			: m_DeltaX(dx), m_DeltaY(dy) {}
		~CursorMoveEvent() = default;

		virtual EventType getType() override { return EventType::CursorMoveEvent; }
	};
}