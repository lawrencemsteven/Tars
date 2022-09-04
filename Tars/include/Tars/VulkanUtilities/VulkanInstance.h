#pragma once

#include <iostream>

#include <vulkan/vulkan.h>

#include <Tars/VulkanUtilities/ValidationLayerInfo.h>

namespace TarsEngine {
	class VulkanInstance {
	private:
		VkInstance m_vkInstance;

		VkDebugUtilsMessengerEXT m_debugMessenger;

	public:
		VulkanInstance(std::string_view applicationName);
		~VulkanInstance();

		VkInstance getVkInstance() {
			return m_vkInstance;
		}

	private:
		/**
		 * Initialize Vulkan
		 * @param applicationName - The name for the application
		 */
		void createVulkanInstance(std::string_view applicationName);

		/**
		 * Setup the Vulkan Validation Layers debug messenger if enabled.
		 */
		void setupDebugMessenger();

		/**
		 * Populate the creation info for a debug messenger
		 * @param createInfo - The creation info to populate
		 */
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

		/**
		 * Check whether validation layers are supported
		 * @return whether validation layers are supported
		 */
		bool checkValidationLayerSupport();

		/**
		 * Get the extensions required by the application.
		 * @return The required extensions.
		 */
		std::vector<const char*> getRequiredExtensions();
	};
}
