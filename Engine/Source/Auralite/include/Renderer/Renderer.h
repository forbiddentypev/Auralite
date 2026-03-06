#pragma once

namespace Auralite {

	enum class RendererAPI
	{
		None = 0,
		OpenGL = 1
	};

	class Renderer
	{
	public:
		inline static RendererAPI GetAPI() { return s_RendererAPI; }

		static void SetClearColorHexString(const std::string& hex);

	private:
		static RendererAPI s_RendererAPI;
	};

}
