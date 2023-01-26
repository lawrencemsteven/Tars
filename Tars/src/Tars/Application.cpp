#include <TarsPCH.h>
#include <Tars/Application.h>

#include <Tars/Events/KeyEvent.h>
#include <Tars/Log.h>

namespace Tars {

	Application::Application() {}


	Application::~Application() {}


	void Application::run() {
		KeyPressedEvent e(20, 0);

		std::cout << e << std::endl;
		TARS_CRITICAL(e);

		while (true) {};
	}

}