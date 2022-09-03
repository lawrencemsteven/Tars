#include <catch2/catch_test_macros.hpp>
#include <Tars/Tars.h>

TEST_CASE("Test Case") {
	std::string_view test = "Test";

	[[maybe_unused]] Tars* tars = Tars::getInstance(test);
}