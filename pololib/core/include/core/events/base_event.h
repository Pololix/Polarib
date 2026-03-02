#pragma once

namespace plb
{
	enum class EventType
	{
		None = 0, //PLB_TODO populate
	};

	class Event
	{
	public:
		bool m_Handled = false;

		virtual EventType getType() = 0;
	};
}