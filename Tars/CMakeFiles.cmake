set(TARS_ENGINE
	"include/Tars/TarsEngine.h"
	"src/TarsEngine.cpp"
)

set(TARS_INPUT
	"include/Tars/Input/InputManager.h"
	"src/Input/InputManager.cpp"
	"include/Tars/Input/InputTypes.h"
)

set(TARS_VULKAN_UTILITIES
	"include/Tars/VulkanUtilities/ValidationLayerInfo.h"
	"src/VulkanUtilities/ValidationLayerInfo.cpp"
	"include/Tars/VulkanUtilities/VulkanBackend.h"
	"src/VulkanUtilities/VulkanBackend.cpp"
	"include/Tars/VulkanUtilities/VulkanInstance.h"
	"src/VulkanUtilities/VulkanInstance.cpp"
	"include/Tars/VulkanUtilities/VulkanDevice.h"
	"src/VulkanUtilities/VulkanDevice.cpp"
	"include/Tars/VulkanUtilities/VulkanSurface.h"
	"src/VulkanUtilities/VulkanSurface.cpp"
)

set(TARS_WINDOW
	"include/Tars/Window/Window.h"
	"src/Window/Window.cpp"
)

set(TARS_FILES
    ${TARS_ENGINE}
    ${TARS_INPUT}
    ${TARS_VULKAN_UTILITIES}
    ${TARS_WINDOW}
)