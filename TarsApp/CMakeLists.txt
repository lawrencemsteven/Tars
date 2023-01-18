set(TARSAPP_INCLUDES

)

set(TARSAPP_SOURCES
	"src/main.cpp"
)

add_executable(TarsApp ${TARSAPP_SOURCES} ${TARSAPP_INCLUDES})

add_dependencies(TarsApp Tars)

target_link_libraries(TarsApp PRIVATE Tars)

target_compile_features(TarsApp PUBLIC cxx_std_20)

target_include_directories(TarsApp
	PUBLIC
		"include"
)

set_project_warnings(TarsApp)