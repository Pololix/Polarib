#pragma once

#include <functional>
#include "core/events.h"

struct GLFWwindow;

namespace plb
{
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
		Window() = default;
		~Window();

		void setPushEventCallback(std::function<void(Event&& event)> pushEventCallback);
		void build(WindowSpecs specs);

		void makeContextCurrent() const;
		void swapBuffers() const;
		void pollEvents() const;
		bool shouldClose() const;
	private:
		GLFWwindow* m_Window = nullptr;
		int m_Width = 0;
		int m_Height = 0;

		std::function<void(Event&& event)> m_PushEventCallback;

		static void framebufferCallback(GLFWwindow* window, int width, int height);
	};
}