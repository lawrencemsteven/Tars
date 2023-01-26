#include <Tars.h>

class ExampleLayer : public Tars::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void onUpdate() override { TARS_INFO("ExampleLayer::Update"); }

	void onEvent(Tars::Event& event) override { TARS_TRACE("{0}", event); }
};

class TarsApp : public Tars::Application {
public:
	TarsApp() { pushLayer(new ExampleLayer()); }

	~TarsApp() {}
};

Tars::Application* Tars::createApplication() { return new TarsApp(); }
