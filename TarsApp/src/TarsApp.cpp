#include <Tars.h>

class ExampleLayer : public Tars::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void onUpdate() override {
		if (Tars::Input::isKeyPressed(TARS_KEY_TAB)) TARS_TRACE("TAB KEY IS PRESSED");
	}

	void onEvent(Tars::Event& event) override {
		// TARS_TRACE("{0}", event);
	}
};

class TarsApp : public Tars::Application {
public:
	TarsApp() {
		pushLayer(new ExampleLayer());
		pushOverlay(new Tars::ImGuiLayer());
	}

	~TarsApp() {}
};

Tars::Application* Tars::createApplication() { return new TarsApp(); }
