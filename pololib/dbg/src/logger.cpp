#include "dbg/logger.h"

#include <vector>
#include <algorithm>

namespace plb
{
	Logger::Logger(const char* name, std::filesystem::path& rootPath)
		: m_Name(name), m_Path(rootPath / (m_Name + ".tmp")), m_OutFile(m_Path)
	{
		
	}

	Logger::~Logger()
	{
		m_OutFile.close();
		m_Path.replace_extension("txt");
	}

	void Logger::log(const char* msg)
	{
		m_OutFile << msg << '\n';
	}

	const char* Logger::getName()
	{
		return m_Name.c_str();
	}

	void LoggerManager::init(const std::filesystem::path& path)
	{
		m_LogsPath = path;
		m_OwnLogger = std::make_unique<Logger>("logger manager", path);
		m_HasInit = true;
	}

	Logger& LoggerManager::getLogger(const char* name)
	{
		if (!m_HasInit) return;

		auto target = std::find_if(m_Loggers.begin(), m_Loggers.end(), [&name](Logger& logger)
		{
			return logger.getName() == name;
		});

		if (target == m_Loggers.end())
		{
			return m_Loggers.emplace_back(name, m_LogsPath);
		}
		else
		{
			return (*target);
		}
	}
}