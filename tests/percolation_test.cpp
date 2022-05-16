#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

//#include "catch.hpp"

#include "Fill.h"

TEST_CASE( "Factorials are computed", "[factorial]" ) {
  
  Fill f;
  REQUIRE(f.percolate(39, 0.4, 3) == false);
  REQUIRE(f.percolate(2, 0.5, 7) == true);
  REQUIRE(f.percolate(5, 0.5, 7) == true);
  REQUIRE(f.percolate(11, 0.5, 7) == true);
  REQUIRE(f.percolate(1, 0.5, 7) == false);
  REQUIRE(f.percolate(19, 0.5, 7) == true);
  REQUIRE(f.percolate(18, 0.5, 7) == false);
  REQUIRE(f.percolate(20, 0.5, 7) == false);
}
