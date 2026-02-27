#pragma once

#include <memory>
#include <functional>

struct GLFWwindow;

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
		Window() = default;
		~Window();

		void setPushEventCallback(std::function<void(std::unique_ptr<Event> e)> fn);
		void build(WindowSpecs specs);

		void makeContextCurrent() const;
		void swapBuffers() const;
		void pollEvents() const;
		bool shouldClose() const;
	private:
		GLFWwindow* m_Window = nullptr;
		int m_Width = 0;
		int m_Height = 0;

		std::function<void(std::unique_ptr<Event> e)> m_PushEventCallback;

		static void framebufferCallback(GLFWwindow* window, int width, int height);
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void cursorPosCallback(GLFWwindow* window, double xPos, double yPos);
		static void cursorEnterCallback(GLFWwindow* window, int entered);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
	};
}