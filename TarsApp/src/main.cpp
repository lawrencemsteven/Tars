#include <Tars/TarsEngine.h>
#include <Tars/Window/Window.h>

int main() {
	std::string_view application_name{"Tars App"};

	Tars::TarsEngine tarsEngine{application_name};
	Tars::Window window{application_name};

	while (!window.shouldClose()) {
		window.pollEvents();

		if (window.getKeyPressed(Tars::Input::KEY_E))
			std::cout << "E KEY PRESSED" << std::endl;
		if (window.getKeyReleased(Tars::Input::KEY_E))
			std::cout << "E KEY RELEASED" << std::endl;
	}
}
