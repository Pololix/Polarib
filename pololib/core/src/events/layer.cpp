#include "core/events/layer.h"

#include "core/events/event_system.h"
#include "core/commands/command_system.h"

namespace plb
{
	void Layer::onAttach(EventSystem* eventSystem, CommandSystem* commandSystem)
	{
		m_EventSystem = eventSystem;
		m_CommandSystem = commandSystem;
	}

	void Layer::onDetach()
	{
		m_EventSystem = nullptr;
		m_CommandSystem = nullptr;
	}
}