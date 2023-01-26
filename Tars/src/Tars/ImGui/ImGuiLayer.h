#pragma once

#include <Tars/Layer.h>

#include <Tars/Events/ApplicationEvent.h>
#include <Tars/Events/KeyEvent.h>
#include <Tars/Events/MouseEvent.h>

namespace Tars {

	class TARS_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach();
		void onDetach();
		void onUpdate();
		void onEvent(Event& event);

	private:
		bool onMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool onMouseMovedEvent(MouseMovedEvent& e);
		bool onMouseScrolledEvent(MouseScrolledEvent& e);
		bool onKeyPressedEvent(KeyPressedEvent& e);
		bool onKeyReleasedEvent(KeyReleasedEvent& e);
		bool onKeyTypedEvent(KeyTypedEvent& e);
		bool onWindowResizeEvent(WindowResizeEvent& e);

	private:
		float m_time = 0.0f;
	};

}