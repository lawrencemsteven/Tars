#include <Tars/VulkanUtilities/VulkanBackend.h>

namespace TarsBackend {
	VulkanBackend::VulkanBackend(std::string_view applicationName)
		: m_vulkanInstance{applicationName},
		  m_vulkanDevice{&m_vulkanInstance} {}

	VulkanBackend::~VulkanBackend() {}
}