#include <Tars/Tars.h>

bool Tars::m_initialized = false;

Tars::Tars(std::string_view applicationName)
	: m_applicationName{applicationName},
	  m_vulkanBackend{m_applicationName} {}

Tars* Tars::getInstance(std::string_view applicationName) {
	static Tars tars{applicationName};

	m_initialized = true;

	return &tars;
}

void Tars::enableValidationLayers() {
	if (m_initialized) {
		throw std::runtime_error(
			"Validation Layers can not be enabled after intialization of Tars!");
	}
	TarsEngine::ValidationLayers::enabled = true;
}