#pragma once

//PLB_TODO: remove io/cstdlib from common header -> move to impl
#include <iostream>
#include <cstdlib>
// supported by a logger system

#ifdef PLB_BUILD_DEBUG
	#define PLB_DEBUG_ASSERT(cond, msg)
#else 
	#define PLB_DEBUG_ASSERT(cond, msg)
#endif

#define PLB_ASSERT(cond, msg)\
	do\
	{\
		if (!(cond))\
		{\
			std::cout << (msg) << '\n';\
			std::abort();\
		}\
	} while (0)
