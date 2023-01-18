#include <Tars/VulkanUtilities/VulkanInstance.h>

namespace TarsBackend {
	VulkanInstance::VulkanInstance(std::string_view applicationName) {
		createVulkanInstance(applicationName);
		setupDebugMessenger();
	}

	VulkanInstance::~VulkanInstance() {
		if (ValidationLayers::enabled) {
			ValidationLayers::DestroyDebugUtilsMessengerEXT(m_vkInstance, m_debugMessenger,
															nullptr);
		}
		vkDestroyInstance(m_vkInstance, nullptr);
	}

	void VulkanInstance::createVulkanInstance(std::string_view applicationName) {
		if (ValidationLayers::enabled && !checkValidationLayerSupport()) {
			throw std::runtime_error("Validation layers requested, but not available!");
		}

		VkApplicationInfo applicationInfo{};
		applicationInfo.sType			 = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		applicationInfo.pApplicationName = applicationName.data();
		applicationInfo.pEngineName		 = "Tars";
		applicationInfo.apiVersion		 = VK_API_VERSION_1_0;


		VkInstanceCreateInfo createInfo{};
		createInfo.sType			= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.flags			= 0;
		createInfo.pApplicationInfo = &applicationInfo;

		auto extensions					   = getRequiredExtensions();
		createInfo.enabledExtensionCount   = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();

		VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
		if (ValidationLayers::enabled) {
			createInfo.enabledLayerCount =
				static_cast<uint32_t>(ValidationLayers::validationLayers.size());
			createInfo.ppEnabledLayerNames = ValidationLayers::validationLayers.data();

			populateDebugMessengerCreateInfo(debugCreateInfo);
			createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
		}
		else {
			createInfo.enabledLayerCount   = 0;
			createInfo.ppEnabledLayerNames = nullptr;
			createInfo.pNext			   = nullptr;
		}

		if (vkCreateInstance(&createInfo, nullptr, &m_vkInstance) != VK_SUCCESS) {
			throw std::runtime_error("Failed to initialize Vulkan!");
		}
	}

	void VulkanInstance::setupDebugMessenger() {
		if (!ValidationLayers::enabled) {
			return;
		}

		VkDebugUtilsMessengerCreateInfoEXT createInfo;
		populateDebugMessengerCreateInfo(createInfo);

		if (ValidationLayers::CreateDebugUtilsMessengerEXT(m_vkInstance, &createInfo, nullptr,
														   &m_debugMessenger) != VK_SUCCESS) {
			throw std::runtime_error("failed to set up debug messenger!");
		}
	}

	void VulkanInstance::populateDebugMessengerCreateInfo(
		VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
		createInfo				   = {};
		createInfo.sType		   = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
									 VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
									 VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
		createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
								 VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
								 VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
		createInfo.pfnUserCallback = ValidationLayers::debugCallback;
	}

	bool VulkanInstance::checkValidationLayerSupport() {
		uint32_t layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		for (const char* layerName : ValidationLayers::validationLayers) {
			bool layerFound = false;

			for (const auto& layerProperties : availableLayers) {
				if (strcmp(layerName, layerProperties.layerName) == 0) {
					layerFound = true;
					break;
				}
			}

			if (!layerFound) {
				return false;
			}
		}

		return true;
	}

	std::vector<const char*> VulkanInstance::getRequiredExtensions() {
		// TODO: Add GLFW extensions as requirement.
		std::vector<const char*> extensions{};

		if (ValidationLayers::enabled) {
			extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
		}

		return extensions;
	}
}