#include <TarsPCH.h>
#include <Tars/Application.h>

#include <Tars/Events/KeyEvent.h>

#include <GLFW/glfw3.h>

namespace Tars {

	Application::Application() { m_window = std::unique_ptr<Window>(Window::create()); }


	Application::~Application() {}


	void Application::run() {
		while (m_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->onUpdate();
		};
	}

}