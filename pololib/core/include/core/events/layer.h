#pragma once

#include "core/events/base_event.h"

namespace plb
{
	using LayerID = unsigned int;

	class Layer
	{
	public:
		bool m_Suspended = false;
		LayerID m_ID;

		virtual void onAttach() {}
		virtual void onSuspend() {}
		virtual void onInclude() {}
		virtual void onDetach() {}

		virtual void onUpdate(float deltaTime) {}
		virtual void onEvent(Event& event) {}
	};
}