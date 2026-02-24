#pragma once

#include "core/events/event.h"

namespace plb
{
	class CommandSystem;

	class Layer
	{
	public:
		bool m_Suspended = false;
		CommandSystem* m_CommandSystem = nullptr;

		virtual void onAttach(CommandSystem* commandSystem);
		virtual void onSuspend() = 0;
		virtual void onInclude() = 0;
		virtual void onDetach();

		virtual void onUpdate(float deltaTime) = 0;
		virtual void onRender() = 0;
		virtual bool onEvent(Event& event) = 0;
	};
}