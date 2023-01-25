include(CMakeFiles.cmake)

add_library(Tars SHARED ${TARS_FILES})

target_compile_features(Tars PUBLIC cxx_std_20)

target_compile_definitions(Tars PRIVATE TARS_BUILD_DLL)

target_link_libraries(Tars
	PRIVATE
		Vulkan::Vulkan
		glm::glm
		glfw
)

target_include_directories(Tars
	PUBLIC
		"./src"
)

set_project_warnings(Tars)

add_subdirectory("tests")