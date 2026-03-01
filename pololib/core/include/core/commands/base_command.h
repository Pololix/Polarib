#pragma once

namespace plb
{
	enum class CommandType
	{
		None = 0,

		Logic, Render
	};

	class Command
	{
	public:
		void execute();
	};
}