#pragma once

#include <filesystem>
#include <fstream>

#define PLB_DEBUG_LOG_LEVEL 0
#define PLB_INFO_LOG_LEVEL 1
#define PLB_WARNING_LOG_LEVEL 2
#define PLB_ERROR_LOG_LEVEL 3

namespace plb
{
	enum class LogLevel
	{
		Debug = 0,
		Info = 1, 
		Warning = 2,
		Error = 3
	};

	class Logger
	{
	public:
		Logger(const char* name, std::filesystem::path& rootPath);
		~Logger();

		void log(const char* msg);
		const char* getName();
	private:
		std::string m_Name;
		std::filesystem::path m_Path;
		std::ofstream m_OutFile;
	};

	class LoggerManager
	{
	public:
		LoggerManager() = default;
		~LoggerManager() = default;

		static void init(const std::filesystem::path& path);
		static Logger& getLogger(const char* name);
	private:
		static std::vector<Logger> m_Loggers;
		static std::unique_ptr<Logger> m_OwnLogger;
		static std::filesystem::path m_LogsPath;
		static inline bool m_HasInit = false;
	};
}