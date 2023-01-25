#pragma once

#ifdef _MSC_VER // VS
extern Tars::Application* Tars::CreateApplication();

int main(int argc, char** argv) {
	auto app = Tars::CreateApplication();
	app->Run();
	delete app;
}
#elif __GNUC__ // GCC
extern Tars::Application* Tars::CreateApplication();

int main(int argc, char** argv) {
	auto app = Tars::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Tars does not support your compiler!
#endif