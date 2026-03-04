#pragma once

//PLB_TODO: remove io/cstdlib from common header -> move to impl
#include <iostream>
#include <cstdlib>
// supported by a logger system

#ifdef PLB_BUILD_DEBUG
	#define PLB_DEBUG_ASSERT(cond, failMsg)
#else 
	#define PLB_DEBUG_ASSERT(cond, failMsg)
#endif

#define PLB_ASSERT(cond, failMsg)\
	do\
	{\
		if (!(cond))\
		{\
			std::cout << (failMsg) << '\n';\
			std::abort();\
		}\
	} while (0)
