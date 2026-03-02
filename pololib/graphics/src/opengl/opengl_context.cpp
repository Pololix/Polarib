#include "graphics/opengl/opengl_context.h"

#include "dbg/logs.h"

namespace plb
{
	void OpenGLContext::init()
	{
		gladLoadGLLoader(m_Loadproc);
		// TODO: log status
	}

	void OpenGLContext::setGLADloadproc(GLADloadproc loadproc)
	{
		m_Loadproc = loadproc;
	}
}