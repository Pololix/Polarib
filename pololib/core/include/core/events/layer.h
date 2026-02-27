#pragma once

namespace plb
{
	class Event;

	class Layer
	{
	public:
		bool m_Suspended = false;

		virtual void onAttach() = 0;
		virtual void onSuspend() = 0;
		virtual void onInclude() = 0;
		virtual void onDetach() = 0;

		virtual void onUpdate(float deltaTime) = 0;
		virtual void onRender() = 0;
		virtual void onEvent(Event& event) = 0;
	};
}