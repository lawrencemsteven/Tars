#include <TarsPCH.h>
#include <Tars/Application.h>

#include <glad/glad.h>

#include <Tars/Input.h>

namespace Tars {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_instance = nullptr;

	Application::Application() {
		TARS_CORE_ASSERT(!s_instance, "Application already exists!");
		s_instance = this;

		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(BIND_EVENT_FN(onEvent));

		m_imGuiLayer = new ImGuiLayer();
		pushOverlay(m_imGuiLayer);

		glGenVertexArrays(1, &m_vertexArray);
		glBindVertexArray(m_vertexArray);

		glGenBuffers(1, &m_vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f,
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glGenBuffers(1, &m_indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);

		unsigned int indices[3] = {
			0,
			1,
			2,
		};

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	}


	Application::~Application() {}


	void Application::pushLayer(Layer* layer) { m_layerStack.pushLayer(layer); }


	void Application::pushOverlay(Layer* layer) { m_layerStack.pushOverlay(layer); }


	void Application::onEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClosed));

		for (auto it = m_layerStack.end(); it != m_layerStack.begin();) {
			(*--it)->onEvent(e);
			if (e.handled) break;
		}
	}


	void Application::run() {
		while (m_running) {
			glClearColor(0.1f, 0.1f, 0.1f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			glBindVertexArray(m_vertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : m_layerStack)
				layer->onUpdate();

			m_imGuiLayer->begin();
			for (Layer* layer : m_layerStack)
				layer->onImGuiRender();
			m_imGuiLayer->end();

			m_window->onUpdate();
		};
	}


	bool Application::onWindowClosed(WindowCloseEvent& e) {
		m_running = false;
		return true;
	}
}