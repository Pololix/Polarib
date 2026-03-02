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

		static void framebufferCallback	(GLFWwindow* window, int width, int height);
		static void keyCallback			(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void cursorPosCallback	(GLFWwindow* window, double xPos, double yPos);
		static void cursorEnterCallback	(GLFWwindow* window, int entered);
		static void mouseButtonCallback	(GLFWwindow* window, int button, int action, int mods);
		static void scrollCallback		(GLFWwindow* window, double xOffset, double yOffset);
	};
}