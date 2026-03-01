#pragma once

#include <memory>
#include <functional>
#include "core/graphics_context.h"

namespace plb
{
	class Event;

	struct WindowSpecs
	{
		unsigned int width = 0;
		unsigned int height = 0;
		const char* name = "";
		bool fullscreen = false;
	};

	class Window
	{
	public:
		virtual ~Window() = 0;

		void setEventCallback(std::function<void(std::unique_ptr<Event> e)> fn) { m_PushEvent = fn; }

		virtual void build(WindowSpecs specs) = 0;

		virtual void pollEvents() const = 0;
		virtual void swapBuffers() const = 0;
		virtual bool shouldClose() const = 0;
		virtual float getTime() const = 0;
	protected:
		std::unique_ptr<GraphicsContext> m_GraphicsContext;
		std::function<void(std::unique_ptr<Event> e)> m_PushEvent;
		int m_Width;
		int m_Height;
	};
}