#include <Tars/Tars.h>

bool Tars::m_initialized = false;

Tars::Tars(std::string_view applicationName)
	: m_applicationName{applicationName},
	  m_vulkanBackend{m_applicationName} {
	m_initialized = true;
}

void Tars::enableValidationLayers() {
	if (m_initialized) {
		throw std::runtime_error(
			"Validation Layers can not be enabled after intialization of Tars!");
	}

	TarsEngine::ValidationLayers::enabled = true;
}