#include <Tars/TarsEngine.h>

namespace Tars {
	bool TarsEngine::m_initialized = false;

	TarsEngine::TarsEngine(std::string_view applicationName)
		: m_applicationName{applicationName},
		  m_window{applicationName},
		  m_vulkanBackend{m_applicationName} {
		m_initialized = true;
	}

	void TarsEngine::enableValidationLayers() {
		if (m_initialized) {
			throw std::runtime_error(
				"Validation Layers can not be enabled after intialization of Tars!");
		}

		TarsBackend::ValidationLayers::enabled = true;
	}
}