#pragma once
#include "Core.h"
#include <stdio.h>

namespace Onyx {

	class AURA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private: //var
		bool m_Running = true;
	};
	// To be defined in CLIENT
	Application* CreateApplication();

}