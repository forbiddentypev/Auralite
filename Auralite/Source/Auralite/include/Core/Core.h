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