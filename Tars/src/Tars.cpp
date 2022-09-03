#include <Tars/Tars.h>

Tars::Tars(std::string_view applicationName)
	: m_applicationName{applicationName},
	  m_vulkanBackend{m_applicationName} {}

Tars* Tars::getInstance(std::string_view applicationName) {
	static Tars tars{applicationName};

	return &tars;
}