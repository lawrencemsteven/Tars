include(CMakeFiles.cmake)

add_library(Tars STATIC ${TARS_FILES})

source_group("Engine" FILES ${TARS_ENGINE})
source_group("Input" FILES ${TARS_INPUT})
source_group("VulkanUtilities" FILES ${TARS_VULKAN_UTILITIES})
source_group("Window" FILES ${TARS_WINDOW})

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