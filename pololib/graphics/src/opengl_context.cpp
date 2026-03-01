#include "graphics/opengl_context.h"

#include <glad/glad.h>
#include "dbg/logger.h"

namespace plb
{
	void OpenGLContext::init()
	{
		if (!gladLoadGLLoader(m_Loadproc))
		{
			Logger& logger = getLogger("window");
			logger.log(LogLevel::Error, []() { return "Unable to init GLAD"; });
			return;
		}
	}

	void OpenGLContext::makeCurrent()
	{

	}

	void OpenGLContext::swapBuffers()
	{

	}
}