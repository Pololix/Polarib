#include "core/commands/command_system.h"

namespace plb
{
	void CommandSystem::push(std::unique_ptr<Command> cmd)
	{
		m_CommandBuffer.push_back(std::move(cmd));
	}

	void CommandSystem::flushCommandBuffer()
	{
		// PLB_TODO: implement event buffer
	}
}