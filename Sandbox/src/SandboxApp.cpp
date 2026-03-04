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

		if(Auralite::Input::IsKeyPressed(AR_KEY_TAB))
			AR_TRACE("Tab key is pressed!(poll)");
	}

	void OnEvent(Auralite::Event& event) override
	{
	if (event.GetEventType() == Auralite::EventType::KeyPressed)
	{
		Auralite::KeyPressedEvent& e = (Auralite::KeyPressedEvent&)event;
		if (e.GetKeyCode() == AR_KEY_A)
			AR_TRACE("A key is pressed!(event)");
		AR_TRACE("{0}", (char)e.GetKeyCode());
	}
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
