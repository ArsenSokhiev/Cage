#pragma once

#ifdef CG_PLATFORM_WINDOWS
	#ifdef CG_BUILD_DLL
		#define CG_API __declspec(dllexport)
	#else
		#define CG_API __declspec(dllimport)
	#endif
#else
	#error Cage support Windows only 
#endif

#define BIT(x) (1 << x)