#pragma once

#include <Tars/Core.h>

#include <Tars/Window.h>
#include <Tars/LayerStack.h>
#include <Tars/Events/Event.h>
#include <Tars/Events/ApplicationEvent.h>

namespace Tars {

	class TARS_API Application {
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		inline Window& getWindow() { return *m_window; }

		inline static Application& get() { return *s_instance; }
	private:
		bool onWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_window;
		bool m_running = true;
		LayerStack m_layerStack;

	private:
		static Application* s_instance;
	};

	// To be defined in client
	Application* createApplication();
}