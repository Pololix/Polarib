#pragma once

#include <iostream> // PLB_TODO: defer logging and assertions avoid including io -> use sink and formatters

#ifdef PLB_BUILD_DEBUG
	#define PLB_DEBUG_ASSERT(cond, msg) do\
		{\
			if(!(cond))\
			{\
				std::cout << msg << '\n';\
				std::abort();\
			}\
		} while (0)
#else
	#define DEBUG_ASSERT(cond, msg) (void)0
#endif

#define PLB_ASSERT(cond, msg) do\
		{\
			if(!(cond))\
			{\
				std::cout << msg << '\n';\
				std::abort();\
			}\
		} while (0)