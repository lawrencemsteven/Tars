#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

#include <Tars/Window/Window.h>

namespace TarsBackend {
	class VulkanSurface {
	private:
		VkSurfaceKHR m_surface;

	public:
		VulkanSurface();
		~VulkanSurface();
	};
}