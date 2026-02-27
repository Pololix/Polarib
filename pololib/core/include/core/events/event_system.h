#pragma once

#include <vector>

namespace plb
{
	class LayerStack;

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
		bool m_Handled = false;

		virtual EventType getType() = 0;
	};

	class EventSystem
	{
	public:
		EventSystem() = default;
		~EventSystem() = default;

		void push(Event&& e);
		void flushEventBuffer(LayerStack& layerStack);
	private:
		std::vector<Event> m_EventBuffer;
	};
}