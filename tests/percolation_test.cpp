
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
//#include "catch.hpp"

#include "Fill.h"

TEST_CASE( "Factorials are computed", "[factorial]" ) {
  
  Fill f;
  REQUIRE( f.percolate(39, 0.4, 3) == false );

}
