#include "Fraction.hpp"

#include <iostream>
#include <string>
#include <stdio.h>
#include "doctest.h"

TEST_CASE("zero in denominator"){
   CHECK_THROWS(Fraction(1,0)); 
}

TEST_CASE("zero in both num and denom"){
    CHECK_THROWS(Fraction(0,0));
}

TEST_CASE("+ operator"){
    Fraction a(1,2), b(2,4), x(3,2), y(5,2);

    CHECK((a+b)==1);
    CHECK((1+a)==x);
    CHECK((x+1)==y);
}

TEST_CASE("- operator"){
    Fraction a(1,2), b(2,4),c(5,3), x(0,1), y(2,3);
   
    CHECK((a-b)==0);
    CHECK((1-a)==x);
    CHECK((c-1)==y);
}

TEST_CASE("* operator"){
    Fraction a(1,2), b(2,4),c(5,3),
     x(5,6), y(0,1);

    CHECK((a*c)==x);
    CHECK((0.0*a)==y);
    CHECK((a*2)==b);
}

TEST_CASE("/ operator"){
    Fraction a(1,2), b(2,4),c(5,3),
    x(3,2), y(5,9);

    CHECK((b/a)==1);
    CHECK((2.5/c)==x);
    CHECK((c/3)==y);
}

TEST_CASE("++ operator"){
    Fraction a(1,2), b(3,2);

    CHECK(++a == b);
    CHECK(a++ == 0.5);
}

TEST_CASE("-- operator"){
    Fraction a(3,1), b(2,1);

    CHECK(--a == b);
    CHECK(a++ == 3);
}

TEST_CASE("< operator"){}

TEST_CASE("> operator"){}

TEST_CASE("<= operator"){}

TEST_CASE(">= operator"){}

TEST_CASE("== operator"){}


