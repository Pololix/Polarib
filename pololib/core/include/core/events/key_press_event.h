#pragma once

#include "core/events/base_event.h"

namespace plb
{
	class KeyPressEvent : public Event
	{
	public:
		const int m_Key;
		const int m_Mods;

		KeyPressEvent(int key, int mods)
			: m_Key(key), m_Mods(mods) {}
		~KeyPressEvent() = default;

		virtual EventType getType() override { return EventType::KeyPressEvent; }

		bool hasMod(int mod) const { return m_Mods & mod; }
	};
}