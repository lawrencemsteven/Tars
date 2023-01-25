#include <Tars.h>

class TarsApp : public Tars::Application {
public:
	TarsApp() {

	}

	~TarsApp() {

	}
};

Tars::Application* Tars::createApplication() {
	return new TarsApp();
}
