#pragma once

namespace plb
{
	enum class EventType
	{
		None = 0,
		WindowResizeEvent, WindowCloseEvent,
		KeyPressEvent, KeyReleaseEvent,
		CursorMoveEvent, CursorEnterEvent, CursorExitEvent, 
		ClickDownEvent, ClickReleaseEvent, ScrollEvent
	};

	class Event
	{
	public:
		bool m_Handled = false;

		virtual EventType getType() = 0;
	};
}