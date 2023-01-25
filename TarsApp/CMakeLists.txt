include(CMakeFiles.cmake)

add_executable(TarsApp ${TARSAPP_FILES})

add_dependencies(TarsApp Tars)

target_link_libraries(TarsApp PRIVATE Tars)

target_compile_features(TarsApp PUBLIC cxx_std_20)

target_include_directories(TarsApp
	PUBLIC
		"src"
)

set_project_warnings(TarsApp)