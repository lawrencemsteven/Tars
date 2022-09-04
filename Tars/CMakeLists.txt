set(TARS_SOURCES
	"src/Tars.cpp"
	"src/VulkanUtilities/ValidationLayerInfo.cpp"
	"src/VulkanUtilities/VulkanBackend.cpp"
	"src/VulkanUtilities/VulkanInstance.cpp"
	"src/VulkanUtilities/VulkanDevice.cpp"
	"src/Window.cpp"
)

set(TARS_HEADERS
	"include/Tars/Tars.h"
	"include/Tars/VulkanUtilities/ValidationLayerInfo.h"
	"include/Tars/VulkanUtilities/VulkanBackend.h"
	"include/Tars/VulkanUtilities/VulkanInstance.h"
	"include/Tars/VulkanUtilities/VulkanDevice.h"
	"include/Tars/Window.h"
)

add_library(Tars STATIC ${TARS_SOURCES} ${TARS_HEADERS})

target_compile_features(Tars PUBLIC cxx_std_20)

target_link_libraries(Tars
	PUBLIC
		Vulkan::Vulkan
		glm::glm
		glfw
)

target_include_directories(Tars
	PUBLIC
		"include"
)

set_project_warnings(Tars)

add_subdirectory("tests")