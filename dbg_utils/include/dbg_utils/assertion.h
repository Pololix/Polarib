#pragma once

#include <cstdlib>
#include <iostream>

#ifdef VERSION_DEBUG
	#define DEBUG_ASSERT(cond, msg)\
		do\
		{\
			if (!(cond)) \
			{\
				std::cout << msg << '\n';\
				std::abort();\
			}\
		} while(0)
#else
	#define DEBUG_ASSERT(cond, msg) ((void)0)
#endif