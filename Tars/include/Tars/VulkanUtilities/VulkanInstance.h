#pragma once

#include <iostream>

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

#include <Tars/VulkanUtilities/ValidationLayerInfo.h>
#include <Tars/Window/Window.h>

namespace TarsBackend {
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
		 * @brief Initialize Vulkan
		 * @param applicationName - The name for the application
		 */
		void createVulkanInstance(std::string_view applicationName);

		/**
		 * @brief Setup the Vulkan Validation Layers debug messenger if enabled.
		 */
		void setupDebugMessenger();

		/**
		 * @brief Populate the creation info for a debug messenger
		 * @param createInfo - The creation info to populate
		 */
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

		/**
		 * @brief Check whether validation layers are supported
		 * @return whether validation layers are supported
		 */
		bool checkValidationLayerSupport();

		/**
		 * @brief Get the extensions required by the application.
		 * @return The required extensions.
		 */
		std::vector<const char*> getRequiredExtensions();
	};
}
