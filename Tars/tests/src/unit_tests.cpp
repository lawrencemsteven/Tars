#include <catch2/catch_test_macros.hpp>

#include <Tars/Tars.h>

TEST_CASE("Test Case") {
	Tars::enableValidationLayers();
	[[maybe_unused]] Tars tars{"Tars Unit Tests"};
}