include(CMakeFiles.cmake)

add_library(Tars STATIC ${TARS_FILES})

target_compile_features(Tars PUBLIC cxx_std_20)

source_group("Windowing/GLFW" FILES ${TARS_WINDOWING_GLFW})
source_group("Graphics/OepnGL" FILES ${TARS_GRAPHICS_OPENGL})
source_group("Tars/Voxel/Blocks" FILES ${TARS_VOXEL_BLOCKS})
source_group("Tars/Voxel/Chunk" FILES ${TARS_VOXEL_CHUNK})
source_group("Tars/Items" FILES ${TARS_ITEMS})
source_group("Tars/Renderer" FILES ${TARS_RENDERER})
source_group("Tars/Events" FILES ${TARS_EVENTS})
source_group("Tars/ImGui" FILES ${TARS_IMGUI})
source_group("Tars/Layers" FILES ${TARS_LAYERS})
source_group("Tars/Logging" FILES ${TARS_LOGGING})
source_group("Tars/Input" FILES ${TARS_INPUT})
source_group("Tars/Main" FILES ${TARS_MAIN})
source_group("" FILES ${TARS_EXTERNAL})

target_compile_definitions(Tars
	PRIVATE
		TARS_DEBUG
		GLFW_INCLUDE_NONE
)

target_link_libraries(Tars
	PRIVATE
		glad::glad
		glfw
		Vulkan::Vulkan
	PUBLIC
		imgui::imgui
		glm::glm
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

add_subdirectory("tests")