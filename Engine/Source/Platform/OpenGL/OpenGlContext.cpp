#include "arpch.h"
#include "Core/Log.h"
#include "OpenGlContext.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Auralite {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		AR_ASSERT(windowHandle, "Window handle is null!");
	}

	OpenGLContext::~OpenGLContext()
	{
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AR_CORE_ASSERT(status, "Failed to initialize Glad!");
		AR_CORE_INFO("OpenGL Info: {0} {1}", (const char*)glGetString(GL_VENDOR), (const char*)glGetString(GL_RENDERER));
		AR_CORE_INFO("Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		AR_CORE_INFO("Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		AR_CORE_INFO("Version: {0}", (const char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
