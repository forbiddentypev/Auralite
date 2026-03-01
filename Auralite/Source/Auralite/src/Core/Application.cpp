#include "arpch.h"
#include "Core/Application.h"
#include "Core/Log.h"
#include "Events/ApplicationEvent.h"

namespace Auralite {

	Application::Application() {
		m_Window = std::unique_ptr <Window>(Window::Create());
	}

	Application::~Application() {}

	void Application::Run() 
	{ 
		WindowResizeEvent e(1280, 720);
		AR_TRACE("{}", e.ToString());
		
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
	
} // namespace Auralite