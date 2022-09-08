set(TARS_UNIT_TESTS_SOURCES
    "src/unit_tests.cpp"
)

add_executable(Tars_unit_tests ${TARS_UNIT_TESTS_SOURCES})

target_link_libraries(Tars_unit_tests PRIVATE Tars Catch2::Catch2WithMain)

target_compile_features(Tars_unit_tests PRIVATE cxx_std_20)
enable_testing()
add_test(NAME Tars_unit_tests COMMAND $<TARGET_FILE:Tars_unit_tests>)

set_project_warnings(Tars_unit_tests)