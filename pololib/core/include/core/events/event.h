#pragma once

namespace plb
{
	enum class EventType
	{
		None = 0,
		WindowResizeEvent, WindowCloseEvent,
		KeyPressedEvent, KeyReleasedEvent,
		MouseMovedEvent, MouseLeftClickedEvent, MouseRightClickedEvent
	};

	class Event
	{
	public:
		virtual EventType getType() = 0;
	};
}