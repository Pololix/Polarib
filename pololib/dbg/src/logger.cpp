#include "dbg/logger.h"

#include <fstream>

namespace plb
{
	Logger::~Logger()
	{

	}

	void Logger::log(std::string&& msg)
	{

	}

	const char* Logger::getName()
	{
		return m_Name.c_str();
	}
}