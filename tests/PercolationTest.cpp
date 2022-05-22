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

TEST_CASE("Percolating various size matrix with probability p=0")
{

  Fill f1 = Fill(16);
  REQUIRE(f1.percolate(39, 0, 16) == false);
  Fill f2 = Fill(14);
  REQUIRE(f2.percolate(2, 0, 14) == false);
  Fill f3 = Fill(12);
  REQUIRE(f3.percolate(5, 0, 12) == false);
  Fill f4 = Fill(10);
  REQUIRE(f4.percolate(11, 0, 10) == false);
  Fill f5 = Fill(8);
  REQUIRE(f5.percolate(1, 0, 8) == false);
  Fill f6 = Fill(6);
  REQUIRE(f6.percolate(19, 0, 6) == false);
  Fill f7 = Fill(4);
  REQUIRE(f7.percolate(18, 0, 4) == false);
  Fill f8 = Fill(2);
  REQUIRE(f8.percolate(20, 0, 2) == false);
}

TEST_CASE("Percolating various size matrix with probability p=1")
{

  Fill f1 = Fill(16);
  REQUIRE(f1.percolate(39, 1, 16) == true);
  Fill f2 = Fill(14);
  REQUIRE(f2.percolate(2, 1, 14) == true);
  Fill f3 = Fill(12);
  REQUIRE(f3.percolate(5, 1, 12) == true);
  Fill f4 = Fill(10);
  REQUIRE(f4.percolate(11, 1, 10) == true);
  Fill f5 = Fill(8);
  REQUIRE(f5.percolate(1, 1, 8) == true);
  Fill f6 = Fill(6);
  REQUIRE(f6.percolate(19, 1, 6) == true);
  Fill f7 = Fill(4);
  REQUIRE(f7.percolate(18, 1, 4) == true);
  Fill f8 = Fill(2);
  REQUIRE(f8.percolate(20, 1, 2) == true);
}
