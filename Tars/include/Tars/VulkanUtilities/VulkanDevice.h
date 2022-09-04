#pragma once

#include <vulkan/vulkan.h>

#include <vector>
#include <optional>

#include <Tars/VulkanUtilities/VulkanInstance.h>

namespace TarsEngine {
	class VulkanDevice {
	private:
		std::optional<uint32_t> m_selectedPhysicalDevice;
		std::vector<VkPhysicalDevice> m_physicalDevices;
		VkDevice m_device;

		struct QueueFamilyIndices {
			std::optional<uint32_t> graphicsFamily;

			bool isComplete() {
				return graphicsFamily.has_value();
			}
		} m_queueFamilyIndices;

	public:
		VulkanDevice(VulkanInstance* vulkanInstance);
		~VulkanDevice();

	private:
		/**
		 * Set the list of all physical devices in m_physicalDevices
		 */
		void listPhysicalDevices(VulkanInstance* vulkanInstance);

		/**
		 * Selects an appropriate physical device from the list of physical devices.
		 * Sets the queueFamilyIndices for that device.
		 */
		void selectPhysicalDevice();

		/**
		 * Initializes the logical device based on the selected physical device.
		 */
		void createLogicalDevice();

		/**
		 * Determins whether or not a device is suitable for the application.
		 * @param device - The device to check suitability
		 * @return device suitability
		 */
		bool isDeviceSuitable(VkPhysicalDevice device);

		/**
		 * Get indices for the queue families of a phyiscal device.
		 * @param device - The device to get the respective queue families from.
		 * @return The corresponding queue family indices.
		 */
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

		/**
		 * Get the current selected physical device.
		 * @return The selected physical device
		 */
		VkPhysicalDevice getPhysicalDevice();
	};
}