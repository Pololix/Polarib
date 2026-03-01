#pragma once 

namespace plb
{
	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = 0;

		virtual void init() = 0;
		virtual void makeCurrent() = 0;
		virtual void swapBuffers() = 0;
	};
}