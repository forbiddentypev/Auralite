#pragma once

#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Auralite {

	class AURA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void OnEvent(Event& e);

		inline static Application & Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

		// Personal Function of coloring
		void SetClearColorHexString(const std::string& hex);

	private:
	    bool OnWindowClose(WindowClosedEvent& e);
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running = true;


	private:
		static Application* s_Instance;
	};
	// To be defined in CLIENT
	Application* CreateApplication();

}
