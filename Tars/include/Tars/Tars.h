#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <Tars/VulkanUtilities/VulkanBackend.h>
#include <Tars/VulkanUtilities/ValidationLayerInfo.h>
#include <Tars/Window.h>

class Tars {
private:
	std::string_view m_applicationName;
	TarsEngine::VulkanBackend m_vulkanBackend;

	static bool m_initialized;

public:
	/**
	 * Create Tars instance provided an application name.
	 * @param applicationName - The name of the application.
	 */
	Tars(std::string_view applicationName);

	/**
	 * Returns the name of the application
	 * @return The name of the application
	 */
	std::string_view getApplicationName() {
		return m_applicationName;
	}

	/**
	 * Enable Vulkan Validation Layers for the application
	 */
	static void enableValidationLayers();
};