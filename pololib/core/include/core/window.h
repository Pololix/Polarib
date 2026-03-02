#pragma once

#include <functional>
#include <memory>
#include "core/graphics_context.h"

namespace plb
{
	class Event;

	struct WindowSpecs
	{
		int width;
		int height;
		const char* name;
		bool fullscreen;
	};

	class Window
	{
	public:
		virtual ~Window() = 0;

		void setEventCallback(std::function<void(std::unique_ptr<Event>)> fn) { m_PushEvent = fn; }

		virtual void build(WindowSpecs specs) = 0;
		virtual void makeContextCurrent() = 0;

		virtual void pollEvents() = 0;
		virtual void swapBuffers() = 0;
		virtual float getTime() = 0;
	protected:
		std::function<void(std::unique_ptr<Event>)> m_PushEvent;
		std::unique_ptr<GraphicsContext> m_Context;
	};
}