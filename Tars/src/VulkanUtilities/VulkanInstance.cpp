#include <Tars/VulkanUtilities/VulkanInstance.h>

namespace TarsEngine {
	VulkanInstance::VulkanInstance(std::string_view applicationName) {
		VkApplicationInfo applicationInfo;
		applicationInfo.sType			 = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		applicationInfo.pApplicationName = applicationName.data();
		applicationInfo.pEngineName		 = "Tars";
		applicationInfo.apiVersion		 = VK_API_VERSION_1_0;


		VkInstanceCreateInfo pCreateInfo;
		pCreateInfo.sType					= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		pCreateInfo.pNext					= nullptr;
		pCreateInfo.flags					= 0;
		pCreateInfo.pApplicationInfo		= &applicationInfo;
		pCreateInfo.enabledExtensionCount	= 0;
		pCreateInfo.enabledLayerCount		= 0;
		pCreateInfo.ppEnabledExtensionNames = 0;
		pCreateInfo.ppEnabledLayerNames		= 0;

		if (vkCreateInstance(&pCreateInfo, nullptr, &m_VkInstance) != VK_SUCCESS) {
			throw std::runtime_error("Failed to initialize Vulkan!");
		}
	}

	VulkanInstance::~VulkanInstance() {
		vkDestroyInstance(m_VkInstance, nullptr);
	}
}