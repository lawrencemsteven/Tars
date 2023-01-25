#include "Tars/VulkanUtilities/VulkanSurface.h"

namespace TarsBackend {
	VulkanSurface::VulkanSurface() {
		VkWin32SurfaceCreateInfoKHR createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	}

	VulkanSurface::~VulkanSurface() {}
}
