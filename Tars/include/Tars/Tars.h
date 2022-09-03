#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <Tars/VulkanUtilities/VulkanBackend.h>
#include <Tars/Window.h>

class Tars {
private:
	std::string_view m_applicationName;
	TarsEngine::VulkanBackend m_vulkanBackend;

	/**
	 * @brief Create Tars instance provided an application name.
	 * @param applicationName - The name of the application.
	 */
	Tars(std::string_view applicationName);

public:
	/**
	 * @brief Get the only instance of the Tars Engine.
	 * @param applicationName - The name of the application.
	 * @return The Tars instance.
	 */
	static Tars* getInstance(std::string_view applicationName = nullptr);

	std::string_view getApplicationName() {
		return m_applicationName;
	}
};