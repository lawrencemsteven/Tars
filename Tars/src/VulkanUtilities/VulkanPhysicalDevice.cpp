#include <Tars/VulkanUtilities/VulkanPhysicalDevice.h>

namespace TarsEngine {
	VulkanPhysicalDevice::VulkanPhysicalDevice(VulkanInstance* vulkanInstance) {
		uint32_t deviceCount;
		vkEnumeratePhysicalDevices(vulkanInstance->getVkInstance(), &deviceCount, nullptr);

		if (deviceCount == 0) {
			throw std::runtime_error("There are no GPUs with Vulkan support!");
		}

		m_physicalDevices.resize(deviceCount);
		vkEnumeratePhysicalDevices(vulkanInstance->getVkInstance(), &deviceCount,
								   m_physicalDevices.data());

		VkPhysicalDeviceProperties props;
		for (const auto& device : m_physicalDevices) {
			if (isDeviceSuitable(device)) {
				m_selectedDevice = device;
			}
		}
	}

	bool VulkanPhysicalDevice::isDeviceSuitable(VkPhysicalDevice device) {
		return true;
	}
}
