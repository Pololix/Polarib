#pragma once

#include "core/config.h"
#include "dbg/logger.h"

//PLB_TODO: back by logger system
// - remove iostream from common header -> implement in a cpp 
#include <iostream>
// - add support for loggers 
// - add support for formatting (maybe logger dependent)

#ifdef PLB_SETTINGS_LOGS_ENABLED
	#if PLB_SETTINGS_LOGS_MINLEVEL <= PLB_DEBUG_LOG_LEVEL
		#define PLB_LOG_DEBUG(msg) std::cout << msg << '\n'
	#else 
		#define PLB_LOG_DEBUG(msg) ((void)0)
	#endif

	#if PLB_SETTINGS_LOGS_MINLEVEL <= PLB_INFO_LOG_LEVEL
		#define PLB_LOG_INFO(msg) std::cout << msg << '\n'
	#else 
		#define PLB_LOG_INFO(msg) ((void)0)
	#endif

	#if PLB_SETTINGS_LOGS_MINLEVEL <= PLB_WARNING_LOG_LEVEL
		#define PLB_LOG_WARNING(msg) std::cout << msg << '\n'
	#else 
		#define PLB_LOG_WARNING(msg) ((void)0)
	#endif

	#if PLB_SETTINGS_LOGS_MINLEVEL <= PLB_ERROR_LOG_LEVEL
		#define PLB_LOG_ERROR(msg) std::cout << msg << '\n'
	#else 
		#define PLB_LOG_ERROR(msg) ((void)0)
	#endif
#else
	#define PLB_LOG_DEBUG(msg) ((void)0)
	#define PLB_LOG_INFO(msg) ((void)0)
	#define PLB_LOG_WARNING(msg) ((void)0)
	#define PLB_LOG_ERROR(msg) ((void)0)
#endif
