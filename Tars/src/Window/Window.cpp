#include <Tars/Window/Window.h>

namespace TarsEngine {
	Window::Window(std::string_view applicationName) {
		glfwInit();

		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

		m_width = static_cast<uint32_t>((mode->width) / 2.0);
		m_height = static_cast<uint32_t>((mode->height) / 2.0);

		m_window = glfwCreateWindow(m_width, m_height, applicationName.data(), nullptr, nullptr);

		glfwSetWindowPos(m_window, (mode->width / 2.0) - (m_width / 2.0),
						 (mode->height / 2.0) - (m_height / 2.0));
	}

	Window::~Window() {
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	bool Window::shouldClose() {
		return glfwWindowShouldClose(m_window);
	}

	void Window::pollEvents() {
		glfwPollEvents();
	}
}
