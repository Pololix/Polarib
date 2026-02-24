#pragma once 

#include <vector>
#include <memory>
#include "core/events/event.h"

namespace plb
{
	class EventSystem
	{
	public: 
		void push(std::unique_ptr<Event> event);
		std::vector<std::unique_ptr<Event>>& getBuffer();
		void clearBuffer();
	private:
		std::vector<std::unique_ptr<Event>> m_EventBuffer;
	};
}