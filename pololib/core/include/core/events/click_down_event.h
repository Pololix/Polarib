#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class ClickDownEvent : public Event
	{
	public:
		const int m_Button;
		const int m_Mods;

		ClickDownEvent(int button, int mods)
			: m_Button(button), m_Mods(mods) {}
		~ClickDownEvent() = default;

		virtual EventType getType() override { return EventType::ClickDownEvent; }

		bool hasMod(int mod) const { return m_Mods & mod; }
	};
}