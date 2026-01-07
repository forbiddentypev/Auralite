#pragma once

#ifdef AR_PLATFORM_WINDOWS
	//#if AR_DYNAMIC_LINK
	#ifdef AR_BUILD_DLL
		#define AURA_API __declspec(dllexport)
	#else
		#define AURA_API __declspec(dllimport)
	#endif
	//#else
		//#define AURA_API
	//#endif
#else
	#error Auralite Only Supports Windows
#endif