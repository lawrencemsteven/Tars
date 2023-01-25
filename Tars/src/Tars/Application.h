#pragma once

#include <Tars/Core.h>
#include <Tars/Events/Event.h>

namespace Tars {

	class TARS_API Application {
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be defined in client
	Application* createApplication();
}