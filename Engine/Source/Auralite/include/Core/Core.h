#pragma once

#if defined(_WIN32)

    #if defined(AR_SHARED_LIB)
        #if defined(AR_BUILD_DLL)
            #define AURA_API __declspec(dllexport)
        #else
            #define AURA_API __declspec(dllimport)
        #endif
    #else
        #define AURA_API
    #endif

#else
    #define AURA_API
#endif

#ifdef AR_DEBUG
	#define AR_ENABLE_ASSERTS
#endif


#ifdef AR_ENABLE_ASSERTS
	#define AR_ASSERT(x, ...) { if(!(x)) { AR_ERROR("Assertion Failed: {0}" __Va_ARGS__); __debugbreak(); } }
	#define AR_CORE_ASSERT(x, ...) { if(!(x)) { AR_ERROR("Assertion Failed: {0}" __Va_ARGS__); __debugbreak(); } }
#else
	#define AR_ASSERT(x, ...)
	#define AR_CORE_ASSERT(x, ...)
#endif // AR_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define AR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)