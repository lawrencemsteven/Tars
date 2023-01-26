#pragma once

#include <Tars/Core.h>
#include <Tars/Events/Event.h>

namespace Tars {

	class TARS_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getName() const { return m_debugName; }

	protected:
		std::string m_debugName;
	};

}