#include <Auralite.h>

int main(int argc, char** argv)
{
    Auralite::Log::Init();
    AR_CORE_WARN("Initialized Log...");
    AR_CORE_WARN("Application started successfully!");
    AR_CORE_INFO("Welcome to Auralite!");
    
    auto app = Auralite::CreateApplication();
    app->Run();

    delete app;
    return 0;
}