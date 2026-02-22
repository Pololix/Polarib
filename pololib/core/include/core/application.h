#pragma once

#include <memory>
#include "platform/window.h"

namespace plb
{
	struct AppSpecs
	{
		 WindowSpecs windowSpecs;
	};

	class Application
	{
	public:
		Application(AppSpecs specs);
		~Application();

		void run();
	private:
		// FOR NOW: single window apps support
		std::unique_ptr<Window> m_window;
	};
}