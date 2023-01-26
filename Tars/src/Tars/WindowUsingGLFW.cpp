#include <TarsPCH.h>

#include <Tars/WindowUsingGLFW.h>

namespace Tars {

	static bool s_GLFWInitialized = false;

	Window* Window::create(const WindowProps& props) { return new WindowUsingGLFW(props); }

	WindowUsingGLFW::WindowUsingGLFW(const WindowProps& props) { init(props); }

	WindowUsingGLFW::~WindowUsingGLFW() { shutdown(); }

	void WindowUsingGLFW::init(const WindowProps& props) {
		m_data.title  = props.title;
		m_data.width  = props.width;
		m_data.height = props.height;

		TARS_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!s_GLFWInitialized) {
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			TARS_CORE_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_window = glfwCreateWindow((int)props.width, (int)props.height, m_data.title.c_str(),
									nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		setVSync(true);
	}

	void WindowUsingGLFW::shutdown() { glfwDestroyWindow(m_window); }

	void WindowUsingGLFW::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowUsingGLFW::setVSync(bool enabled) {
		if (enabled) glfwSwapInterval(1);
		else glfwSwapInterval(0);

		m_data.vSync = enabled;
	}

	bool WindowUsingGLFW::isVSync() const { return m_data.vSync; }
}