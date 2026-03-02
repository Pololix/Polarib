#pragma once

#include <sstream>

namespace plb
{
	enum class LogLevel
	{
		Debug = 0,
		Info = 1, 
		Warning = 2,
		Error = 3
	};

#define PLB_DEBUG_LOG_LEVEL 0
#define PLB_INFO_LOG_LEVEL 1
#define PLB_WARNING_LOG_LEVEL 2
#define PLB_ERROR_LOG_LEVEL 3

	class Logger
	{
	public:
		Logger(std::string&& name)
			: m_Name(name) {}
		~Logger();

		void log(std::string&& msg);
		const char* getName();
	private:
		std::string m_Name;
		std::stringstream m_Buffer;
	};
}