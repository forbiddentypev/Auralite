#include "arpch.h"
#include "Core/Application.h"
#include "Core/Log.h"
#include "Events/ApplicationEvent.h"

namespace Auralite {

    #define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr <Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOvrerlay(layer);
	}

	// To set Colors out of Hex
	void Application::SetClearColorHexString(const std::string& hex)
	{
	    std::string h = hex;

            if (h[0] == '#')
                h = h.substr(1);

            if (h.length() != 6)
                return;

            auto hexToInt = [](char c)
            {
                if (c >= '0' && c <= '9') return c - '0';
                if (c >= 'a' && c <= 'f') return c - 'a' + 10;
                if (c >= 'A' && c <= 'F') return c - 'A' + 10;
                return 0;
            };

            int r = hexToInt(h[0]) * 16 + hexToInt(h[1]);
            int g = hexToInt(h[2]) * 16 + hexToInt(h[3]);
            int b = hexToInt(h[4]) * 16 + hexToInt(h[5]);

            glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
        }

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatcher<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClose));

		AR_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled())
				break;
		}

	}

	void Application::Run()
	{
		while (m_Running)
		{
			SetClearColorHexString("#0c0c0c"); //#0c0c0c Dark gray Color
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowClosedEvent& e)
	{
		m_Running = false;
		return true;
	}

} // namespace Auralite
