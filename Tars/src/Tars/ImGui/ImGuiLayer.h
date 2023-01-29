#pragma once

#include <Tars/Layer.h>

#include <Tars/Events/ApplicationEvent.h>
#include <Tars/Events/KeyEvent.h>
#include <Tars/Events/MouseEvent.h>

namespace Tars {

	class ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onImGuiRender() override;

		void begin();
		void end();

	private:
		float m_time = 0.0f;
	};

}