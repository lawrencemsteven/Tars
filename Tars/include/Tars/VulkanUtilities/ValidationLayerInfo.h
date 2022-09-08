#pragma once

#include <iostream>
#include <vector>

#include <vulkan/vulkan.h>

namespace TarsEngine::ValidationLayers {
	extern bool enabled;

	const std::vector<const char*> validationLayers = {"VK_LAYER_KHRONOS_validation"};

	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance,
										  const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
										  const VkAllocationCallbacks* pAllocator,
										  VkDebugUtilsMessengerEXT* pDebugMessenger);

	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger,
									   const VkAllocationCallbacks* pAllocator);

	VKAPI_ATTR VkBool32 VKAPI_CALL
	debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
				  VkDebugUtilsMessageTypeFlagsEXT messageType,
				  const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
}