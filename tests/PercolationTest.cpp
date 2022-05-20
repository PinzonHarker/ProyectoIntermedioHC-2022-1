#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

//#include "catch.hpp"

#include "../libs/Fill.h"

TEST_CASE("Percolating various matrix")
{

  Fill f1 = Fill(3);
  REQUIRE(f1.percolate(39, 0.4, 3) == false);
  Fill f2 = Fill(7);
  REQUIRE(f2.percolate(2, 0.5, 7) == true);
  Fill f3 = Fill(7);
  REQUIRE(f3.percolate(5, 0.5, 7) == true);
  Fill f4 = Fill(7);
  REQUIRE(f4.percolate(11, 0.5, 7) == true);
  Fill f5 = Fill(7);
  REQUIRE(f5.percolate(1, 0.5, 7) == false);
  Fill f6 = Fill(7);
  REQUIRE(f6.percolate(19, 0.5, 7) == true);
  Fill f7 = Fill(7);
  REQUIRE(f7.percolate(18, 0.5, 7) == false);
  Fill f8 = Fill(7);
  REQUIRE(f8.percolate(20, 0.5, 7) == false);
}
