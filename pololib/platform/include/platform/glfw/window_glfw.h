#pragma once

#include "core/window.h"

struct GLFWwindow;

namespace plb
{
	class WindowGLFW : public Window
	{
	public:
		WindowGLFW();
		~WindowGLFW() = default;

		void build(WindowSpecs specs) override;
		void makeContextCurrent() override;

		void pollEvents() override;
		void swapBuffers() override;
		float getTime() override;
	private:
		GLFWwindow* m_Window = nullptr;

		// window events
		static void closeCallback			(GLFWwindow* window);
		static void framebufferSizeCallback	(GLFWwindow* window, int width, int height);
		
		// cursor inputs
		static void cursorEnterCallback		(GLFWwindow* window, int entered);
		static void cursorPosCallback		(GLFWwindow* window, double xPos, double yPos);
		static void scrollCallback			(GLFWwindow* window, double xOffset, double yOffset);

		// mouse inputs
		static void mouseButtonCallback		(GLFWwindow* window, int button, int action, int mods);
		
		// key inputs
		static void keyCallback				(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}