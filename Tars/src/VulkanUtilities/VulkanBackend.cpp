#include <Tars/VulkanUtilities/VulkanBackend.h>

namespace TarsEngine {
	VulkanBackend::VulkanBackend(std::string_view applicationName)
		: m_vulkanInstance{applicationName},
		  m_vulkanPhysicalDevice{&m_vulkanInstance} {}

	VulkanBackend::~VulkanBackend() {}
}