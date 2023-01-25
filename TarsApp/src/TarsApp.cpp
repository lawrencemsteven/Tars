#include <Tars.h>

class TarsApp : public Tars::Application {
public:
	TarsApp() {

	}

	~TarsApp() {

	}
};

Tars::Application* Tars::CreateApplication() {
	return new TarsApp();
}
