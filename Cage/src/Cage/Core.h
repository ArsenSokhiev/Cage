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

#ifdef CG_ENABLE_ASSERTS
	#define CG_ASSERT(x, ...) { if(!(x)) { CG_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CG_CORE_ASSERT(x, ...) { if(!(x)) { CG_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CG_ASSERT(x, ...)
	#define CG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)