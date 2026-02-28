#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class WindowResizeEvent : public Event
	{
	public:
		const int m_DeltaWidth;
		const int m_DeltaHeight;

		WindowResizeEvent(int dWidth, int dHeight) 
			: m_DeltaWidth(dWidth), m_DeltaHeight(dHeight) {}
		~WindowResizeEvent() = default;

		virtual EventType getType() override { return EventType::WindowResizeEvent; }
	};
}