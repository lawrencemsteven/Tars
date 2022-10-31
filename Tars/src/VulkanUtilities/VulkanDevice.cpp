#include <Tars/VulkanUtilities/VulkanDevice.h>

namespace TarsEngine {
	VulkanDevice::VulkanDevice(VulkanInstance* vulkanInstance) {
		listPhysicalDevices(vulkanInstance);
		selectPhysicalDevice();
		createLogicalDevice();
	}

	VulkanDevice::~VulkanDevice() {
		vkDeviceWaitIdle(m_device);
		vkDestroyDevice(m_device, nullptr);
	}

	void VulkanDevice::listPhysicalDevices(VulkanInstance* vulkanInstance) {
		uint32_t deviceCount;
		vkEnumeratePhysicalDevices(vulkanInstance->getVkInstance(), &deviceCount, nullptr);

		if (deviceCount == 0) {
			throw std::runtime_error("There are no GPUs with Vulkan support!");
		}

		m_physicalDevices.resize(deviceCount);
		vkEnumeratePhysicalDevices(vulkanInstance->getVkInstance(), &deviceCount,
								   m_physicalDevices.data());
	}

	void VulkanDevice::selectPhysicalDevice() {
		uint32_t i = 0;
		for (const VkPhysicalDevice device : m_physicalDevices) {
			if (isDeviceSuitable(device)) {
				m_selectedPhysicalDevice = i;
				m_queueFamilyIndices	 = findQueueFamilies(device);
				break;
			}
			i++;
		}
	}

	void VulkanDevice::createLogicalDevice() {
		VkDeviceQueueCreateInfo queueCreateInfo{};
		queueCreateInfo.sType			 = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateInfo.pNext			 = nullptr;
		queueCreateInfo.flags			 = 0;
		queueCreateInfo.queueFamilyIndex = m_queueFamilyIndices.graphicsFamily.value();
		queueCreateInfo.queueCount		 = 1;

		float queuePriority				 = 1.0f;
		queueCreateInfo.pQueuePriorities = &queuePriority;

		// TODO: Only enable requested features
		VkPhysicalDeviceFeatures deviceFeatures{};
		vkGetPhysicalDeviceFeatures(getPhysicalDevice(), &deviceFeatures);

		VkDeviceCreateInfo createInfo{};
		createInfo.sType				   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		createInfo.pNext				   = nullptr;
		createInfo.flags				   = 0;
		createInfo.pQueueCreateInfos	   = &queueCreateInfo;
		createInfo.enabledLayerCount	   = 0;
		createInfo.ppEnabledLayerNames	   = nullptr;
		createInfo.enabledExtensionCount   = 0;
		createInfo.ppEnabledExtensionNames = nullptr;
		createInfo.pEnabledFeatures		   = &deviceFeatures;

		if (ValidationLayers::enabled) {
			createInfo.enabledLayerCount =
				static_cast<uint32_t>(ValidationLayers::validationLayers.size());
			createInfo.ppEnabledLayerNames = ValidationLayers::validationLayers.data();
			std::cout << "Validation Layers Enabled!\n";
		}

		if (vkCreateDevice(getPhysicalDevice(), &createInfo, nullptr, &m_device) != VK_SUCCESS) {
			throw std::runtime_error("Error creating the logical device!");
		}
	}

	bool VulkanDevice::isDeviceSuitable(VkPhysicalDevice device) {
		// TODO: Better Device Selection
		VkPhysicalDeviceProperties props;
		vkGetPhysicalDeviceProperties(device, &props);

		return props.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;
	}

	VulkanDevice::QueueFamilyIndices VulkanDevice::findQueueFamilies(VkPhysicalDevice device) {
		QueueFamilyIndices indices;

		uint32_t queueFamilyPropertyCount;
		vkGetPhysicalDeviceQueueFamilyProperties(getPhysicalDevice(), &queueFamilyPropertyCount,
												 nullptr);

		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyPropertyCount);

		vkGetPhysicalDeviceQueueFamilyProperties(getPhysicalDevice(), &queueFamilyPropertyCount,
												 queueFamilies.data());

		uint32_t i = 0;
		for (const auto& queueFamily : queueFamilies) {
			if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
				indices.graphicsFamily = i;
			}

			if (indices.isComplete()) {
				break;
			}

			i++;
		}

		return indices;
	}

	VkPhysicalDevice VulkanDevice::getPhysicalDevice() {
		if (m_selectedPhysicalDevice.has_value()) {
			return m_physicalDevices[m_selectedPhysicalDevice.value()];
		}
		return nullptr;
	}
}
