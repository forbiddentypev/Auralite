#include <Auralite.h>

class Sandbox : public Auralite::Application
{
	public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Auralite::Application* Auralite::CreateApplication()
{
	return new Sandbox();
}