#pragma once

#include <Tars/Core.h>
#include <Tars/Events/Event.h>
#include <Tars/Events/ApplicationEvent.h>
#include <Tars/Window.h>

namespace Tars {

	class TARS_API Application {
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);
	private:
		bool onWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_window;
		bool m_running = true;
	};

	// To be defined in client
	Application* createApplication();
}