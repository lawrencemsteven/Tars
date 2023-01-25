#pragma once

#include <Tars/Core.h>

namespace Tars {

	class TARS_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}