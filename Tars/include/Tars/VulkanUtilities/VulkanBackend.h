#pragma once

#include <Tars/VulkanUtilities/VulkanInstance.h>
#include <Tars/VulkanUtilities/VulkanPhysicalDevice.h>

namespace TarsEngine {
	class VulkanBackend {
	private:
		VulkanInstance m_vulkanInstance;
		VulkanPhysicalDevice m_vulkanPhysicalDevice;

	public:
		VulkanBackend(std::string_view applicationName);
		~VulkanBackend();
	};
}
