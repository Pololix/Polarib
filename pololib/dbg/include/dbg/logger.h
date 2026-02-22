#pragma once

#include <unordered_map>
#include <functional>
#include <iostream> // TODO: remove iostream from logger and assert

namespace plb
{
	enum class LogLevel
	{
		Debug, Info, Warning, Error // FOR NOW: irrelevant
	};

	class Logger
	{
	public:
		Logger(LogLevel minLevel)
			: m_MinLevel(minLevel) {}

		void log(LogLevel level, std::function<std::string()> stringProducer)
		{
			if (level < m_MinLevel) return;

			std::cout << stringProducer() << '\n';
		}
	private:
		LogLevel m_MinLevel;
	};

	static Logger& getLogger(std::string name)
	{
		static std::unordered_map<std::string, Logger> loggerMap;
		static Logger dbgLogger(LogLevel::Debug);

		if (loggerMap.find(name) == loggerMap.end())
		{
			Logger newLogger(LogLevel::Debug);
			loggerMap.emplace(name, newLogger);

			dbgLogger.log(LogLevel::Debug, [&name]() { return "New logger: " + name; });

			return newLogger;
		}
		else
		{
			return loggerMap.at(name);
		}
	}
}