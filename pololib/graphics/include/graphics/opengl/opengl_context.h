#pragma once

#include <glad/glad.h>
#include "core/graphics_context.h"

namespace plb
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext() = default;
		~OpenGLContext() = default;

		void init() override;
		void setGLADloadproc(GLADloadproc loadproc);
	private:
		GLADloadproc m_Loadproc;
	};
}