#pragma once
#include "Core/Core.h"

#include "Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Auralite {
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual ~OpenGLContext();
		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}
