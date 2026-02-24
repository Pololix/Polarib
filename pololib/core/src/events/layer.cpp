#include "core/events/layer.h"

#include "core/commands/command_system.h"

namespace plb
{
	void Layer::onAttach(CommandSystem* commandSystem)
	{
		m_CommandSystem = commandSystem;
	}

	void Layer::onDetach()
	{
		m_CommandSystem = nullptr;
	}
}