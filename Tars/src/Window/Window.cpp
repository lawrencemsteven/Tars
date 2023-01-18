#include <Tars/Window/Window.h>

namespace Tars {
	Window::Window(std::string_view applicationName) {
		glfwInit();

		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

		// Set width and height to monitor resolution / 2
		m_width = static_cast<uint32_t>((mode->width) / 2.0);
		m_height = static_cast<uint32_t>((mode->height) / 2.0);

		m_window = glfwCreateWindow(m_width, m_height, applicationName.data(), nullptr, nullptr);
		
		if (m_window == NULL) {
			std::cerr << "Failed to create GLFW Window!" << std::endl;
		}

		// Center Window based on Monitor resolution
		glfwSetWindowPos(m_window, (mode->width / 2.0) - (m_width / 2.0),
						 (mode->height / 2.0) - (m_height / 2.0));

		glfwSetKeyCallback(m_window, keyCallback);
	}

	Window::~Window() {
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	bool Window::shouldClose() {
		return glfwWindowShouldClose(m_window);
	}

	void Window::pollEvents() {
		m_inputManager.resetChanged();
		glfwPollEvents();
	}

	bool Window::getKey(Tars::Input::Key key) {
		return m_inputManager.getKey(key);
	}

	bool Window::getKeyPressed(Tars::Input::Key key) {
		return m_inputManager.getKeyPressed(key);
	}

	bool Window::getKeyReleased(Tars::Input::Key key) {
		return m_inputManager.getKeyReleased(key);
	}

	void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		m_inputManager.keyCallback(static_cast<Input::Key>(key), scancode, static_cast<Input::State>(action), mods);
	}
}
