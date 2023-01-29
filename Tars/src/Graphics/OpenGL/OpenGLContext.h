#pragma once

#include <Tars/Renderer/GraphicsContext.h>

struct GLFWwindow;

namespace Tars {

	class OpenGLContext : public GraphicsContext {
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void init() override;
		virtual void swapBuffers() override;

	private:
		GLFWwindow* m_windowHandle;
	};

}