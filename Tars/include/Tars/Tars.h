#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <Tars/VulkanUtilities/VulkanBackend.h>
#include <Tars/VulkanUtilities/ValidationLayerInfo.h>
#include <Tars/Window/Window.h>

class Tars {
private:
	std::string_view m_applicationName;
	TarsEngine::Window m_window;
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

	/**
	 * Whether or not the application should close
	 * @return whether or not the application should close
	 */
	bool shouldClose();

	/**
	 * Poll events in the system
	 */
	void pollEvents();
};