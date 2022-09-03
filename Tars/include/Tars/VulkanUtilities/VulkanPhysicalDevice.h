#pragma once

#include <vulkan/vulkan.h>

#include <vector>

#include <Tars/VulkanUtilities/VulkanInstance.h>

namespace TarsEngine {
	class VulkanPhysicalDevice {
	private:
		VkPhysicalDevice m_selectedDevice;
		std::vector<VkPhysicalDevice> m_physicalDevices;

	public:
		VulkanPhysicalDevice(VulkanInstance* vulkanInstance);

	private:
		bool isDeviceSuitable(VkPhysicalDevice device);
	};
}