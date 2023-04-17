#include "Fraction.hpp"

#include <iostream>
#include <string>
#include <stdio.h>
#include "doctest.h"

TEST_CASE("zero in denominator"){
    CHECK_THROWS(Fraction(2,0));
}

TEST_CASE("zero in both num and denom"){
    CHECK_THROWS(Fraction(0,0));
}