#include <TarsPCH.h>
#include <Graphics/OpenGL/OpenGLContext.h>



#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Tars {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_windowHandle(windowHandle) {
		TARS_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::init() {
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TARS_CORE_ASSERT(status, "Failed to initialize Glad!");
	}

	void OpenGLContext::swapBuffers() { glfwSwapBuffers(m_windowHandle); }

}