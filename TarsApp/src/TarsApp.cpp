#include <Tars.h>

#include <imgui.h>

class ExampleLayer : public Tars::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	virtual void onUpdate() override {
		if (Tars::Input::isKeyPressed(TARS_KEY_TAB)) TARS_TRACE("TAB KEY IS PRESSED");
	}

	virtual void onImGuiRender() override {
		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();
	}
};

class TarsApp : public Tars::Application {
public:
	TarsApp() {
		pushLayer(new ExampleLayer());
	}

	~TarsApp() {}
};

Tars::Application* Tars::createApplication() { return new TarsApp(); }
