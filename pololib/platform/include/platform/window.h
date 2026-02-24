#pragma once

struct GLFWwindow;

namespace plb
{
	struct WindowSpecs
	{
		unsigned int width = 0;
		unsigned int height = 0;
		const char* name = "";
		bool fullscreen = false;
		bool resizeable = false;
	};

	class Window
	{
	public:
		Window(WindowSpecs specs);
		~Window();

		void makeContextCurrent() const;
		void swapBuffers() const;
		void pollEvents() const;
		bool shouldClose() const;
	private:
		GLFWwindow* m_Window = nullptr;
	};
}