include(CMakeFiles.cmake)

add_library(Tars SHARED ${TARS_FILES})

target_compile_features(Tars PUBLIC cxx_std_20)

source_group("Tars/Events" FILES ${TARS_EVENTS})
source_group("Tars" FILES ${TARS_MAIN})
source_group("" FILES ${TARS_EXTERNAL})

target_compile_definitions(Tars
	PRIVATE
		TARS_BUILD_DLL
		TARS_ENABLE_ASSERTS
		GLFW_INCLUDE_NONE
)

target_link_libraries(Tars
	PRIVATE
		glad::glad
		glfw
		glm::glm
		Vulkan::Vulkan
	PUBLIC
		spdlog::spdlog
)

target_include_directories(Tars
	PUBLIC
		"./src"
)

target_precompile_headers(Tars
	INTERFACE
		"./src/TarsPCH.h"
)

set_project_warnings(Tars)

add_subdirectory("tests")