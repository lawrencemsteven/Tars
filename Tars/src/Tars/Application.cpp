#include <Tars/Application.h>

#include <Tars/Events/ApplicationEvent.h>
#include <Tars/Log.h>

#include <iostream>

namespace Tars {

	Application::Application() {}


	Application::~Application() {}


	void Application::run() {
		WindowResizeEvent e(1280, 720);

		std::cout << e << std::endl;
		TARS_CRITICAL(e);

		while (true) {};
	}

}