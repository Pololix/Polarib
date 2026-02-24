#pragma once

#include "core/events/event.h"

namespace plb
{
	class EventSystem;
	class CommandSystem;

	class Layer
	{
	public:
		bool m_Suspended = false;
		EventSystem* m_EventSystem = nullptr;
		CommandSystem* m_CommandSystem = nullptr;

		virtual void onAttach(EventSystem* eventSystem, CommandSystem* commandSystem);
		virtual void onSuspend() = 0;
		virtual void onInclude() = 0;
		virtual void onDetach();

		virtual void onUpdate(float deltaTime) = 0;
		virtual void onRender() = 0;
		virtual bool onEvent(Event& event) = 0;
	};
}