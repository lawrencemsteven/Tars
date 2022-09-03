#pragma once

#include <iostream>

#include <vulkan/vulkan.h>

namespace TarsEngine {
	class VulkanInstance {
	private:
		VkInstance m_VkInstance;

	public:
		VulkanInstance(std::string_view applicationName);

		~VulkanInstance();

		VkInstance getVkInstance() {
			return m_VkInstance;
		}
	};
}
