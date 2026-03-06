#include "arpch.h"
#include "Renderer.h"

#include <glad/glad.h>

namespace Auralite {
	RendererAPI Renderer::s_RendererAPI = RendererAPI::OpenGL;

	void Renderer::SetClearColorHexString(const std::string& hex)
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

}
