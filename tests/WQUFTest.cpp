#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

//#include "catch.hpp"

#include "../libs/WQUF.h"
#include <vector>

TEST_CASE("Verification for algorithm", "[WQUF]")
{

  WQUF test = WQUF(4);
  test.myUnion(1, 3);
  std::vector<int> first = {0, 1, 2, 1};
  REQUIRE(test.getParent() == first);
  REQUIRE(test.getParent() == first);
}
  