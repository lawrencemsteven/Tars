#pragma once

#include <Tars/VulkanUtilities/VulkanInstance.h>
#include <Tars/VulkanUtilities/VulkanDevice.h>

namespace TarsEngine {
	class VulkanBackend {
	private:
		VulkanInstance m_vulkanInstance;
		VulkanDevice m_vulkanDevice;

	public:
		VulkanBackend(std::string_view applicationName);
		~VulkanBackend();
	};
}
