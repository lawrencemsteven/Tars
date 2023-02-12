#pragma once

extern Tars::Application* Tars::createApplication();

int main(int argc, char** argv) {
	Tars::Log::init();
	TARS_CORE_WARN("Initialized Log!");
	int a = 5;
	TARS_INFO("Hello! Var={0}", a);

	auto app = Tars::createApplication();
	app->run();
	delete app;
}