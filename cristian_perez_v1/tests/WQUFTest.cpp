#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

//#include "catch.hpp"

#include "../libs/WQUF.h"
#include <vector>
#include <iostream>

TEST_CASE("Verification for algorithm", "[WQUF]")
{
  int listUnions[9][2] = {
      {4, 3},
      {3, 8},
      {6, 5},
      {9, 4},
      {2, 1},
      {5, 0},
      {7, 2},
      {6, 1},
      {7, 3}};
  WQUF test = WQUF(10);
  std::vector<int> ar;
  for (auto& row : listUnions)
  {
    test.myUnion(row[0], row[1]);
  }
  for (int i = 0; i < 10; i++)
  {
    ar.push_back(test.find(i));
  }
  std::vector<int> arr = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
  REQUIRE(ar == arr);
}

TEST_CASE("For a simple union")
{
  WQUF test = WQUF(10);
  std::vector<int> ar;
  test.myUnion(1, 3);
  for (int i = 0; i < 10; i++)
  {
    ar.push_back(test.find(i));
  }
  std::vector<int> arr = {0, 1, 2, 1, 4, 5, 6, 7, 8, 9};
  REQUIRE(ar == arr);
}


TEST_CASE("For bad inputs")
{
  WQUF test;
  REQUIRE_THROWS(test = WQUF(-1));
  
}