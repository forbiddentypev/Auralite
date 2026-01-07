#pragma once
#include "Application.h" 
using namespace Onyx;

#ifdef AR_PLATFORM_WINDOWS


int main(int argc, char** argv)
{
	Onyx::Log::Init();
	AR_CORE_WARN("Initialized Log!");
    
    auto app = CreateApplication(); // forward declaration suffices
    app->Run();
    delete app;
    return 0;
}


#endif
