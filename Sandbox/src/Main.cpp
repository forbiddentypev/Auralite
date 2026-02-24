#include <Auralite.h>

int main(int argc, char** argv)
{
    Auralite::Log::Init();
    AR_CORE_WARN("Initialized Log!");

    auto app = Auralite::CreateApplication();
    app->Run();

    delete app;
    return 0;
}