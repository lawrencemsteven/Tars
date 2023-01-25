#pragma once

#include <Tars/VulkanUtilities/VulkanBackend.h>
#include <Tars/VulkanUtilities/ValidationLayerInfo.h>
#include <Tars/Window/Window.h>

namespace Tars {
	class TarsEngine {
	private:
		std::string_view m_applicationName;
		TarsBackend::Window m_window;
		TarsBackend::VulkanBackend m_vulkanBackend;

		static bool m_initialized;

	public:
		/**
		 * @brief Create Tars instance provided an application name.
		 * @param applicationName - The name of the application.
		 */
		TarsEngine(std::string_view applicationName);

		/**
		 * @brief Returns the name of the application
		 * @return The name of the application
		 */
		std::string_view getApplicationName() {
			return m_applicationName;
		}

		/**
		 * @brief Enable Vulkan Validation Layers for the application
		 */
		static void enableValidationLayers();
	};
}