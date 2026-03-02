#pragma once

#include <vector>
#include <memory>

namespace plb
{
	class Event;
	class LayerStack;

	class EventSystem
	{
	public:
		EventSystem() = default;
		~EventSystem() = default;

		void push(std::unique_ptr<Event> e);
		void flush(LayerStack& stack);
	private:
		std::vector<Event> m_EventBuffer;
	};
}