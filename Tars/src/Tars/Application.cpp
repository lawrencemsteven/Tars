#include <TarsPCH.h>
#include <Tars/Application.h>

#include <GLFW/glfw3.h>

namespace Tars {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(BIND_EVENT_FN(onEvent));
	}


	Application::~Application() {}


	void Application::onEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClosed));
		TARS_CORE_TRACE("{0}", e);
	}


	void Application::run() {
		while (m_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->onUpdate();
		};
	}


	bool Application::onWindowClosed(WindowCloseEvent& e) {
		m_running = false;
		return true;
	}
}