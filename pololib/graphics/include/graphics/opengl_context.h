#pragma once 

#include "core/graphics_context.h"

namespace plb
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(void* nativeWindow, GLADloadproc loadproc)
			: m_NativeWindow(nativeWindow), m_Loadproc(loadproc) {}
		~OpenGLContext() override;

		void init() override;
		void makeCurrent() override;
		void swapBuffers() override;
	private:
		void* m_NativeWindow;
		GLADloadproc m_Loadproc;
	};
}