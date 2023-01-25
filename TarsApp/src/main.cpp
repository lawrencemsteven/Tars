#include <Tars/TarsEngine.h>
#include <Tars/Window/Window.h>

int main() {
	std::string_view application_name{"Tars App"};

	Tars::TarsEngine tarsEngine{application_name};
	TarsBackend::Window window{application_name};

	while (!window.shouldClose()) {
		window.pollEvents();

		if (window.getKeyPressed(Tars::Input::TARS_KEY_E))
			std::cout << "E Pressed" << std::endl;
		if (window.getKeyReleased(Tars::Input::TARS_KEY_E))
			std::cout << "E Released" << std::endl;
	}
}
