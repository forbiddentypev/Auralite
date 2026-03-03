#include <Auralite.h>

class ExampleLayer : public Auralite::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		AR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Auralite::Event& event) override
	{
		AR_INFO("ExampleLayer::OnEvent");
	}
};

class Sandbox : public Auralite::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Auralite::ImGuiLayer());
	}

	~Sandbox() {}
};
Auralite::Application* Auralite::CreateApplication()
{
	return new Sandbox();
}
