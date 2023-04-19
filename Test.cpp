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

TEST_CASE("divided with zero"){
    Fraction a(1,2);

    CHECK_THROWS(a/0.0);
}

TEST_CASE("+ operator"){
    Fraction a(1,2), b(2,4), x(3,2), y(5,2);

    CHECK((a+b)==1.0);
    CHECK((1.0+a)==x);
    CHECK((x+1.0)==y);
}

TEST_CASE("- operator"){
    Fraction a(1,2), b(2,4),c(5,3), x(0,1), y(2,3);
   
    CHECK((a-b)==0.0);
    CHECK((1.0-a)==x);
    CHECK((c-1.0)==y);
}

TEST_CASE("* operator"){
    Fraction a(1,2), b(2,4),c(5,3),
     x(5,6), y(0,1);

    CHECK((a*c)==x);
    CHECK((0.0*a)==y);
    CHECK((a*2.0)==b);
}

TEST_CASE("/ operator"){
    Fraction a(1,2), b(2,4),c(5,3),
    x(3,2), y(5,9);

    CHECK((b/a)==1.0);
    CHECK((2.5/c)==x);
    CHECK((c/3.0)==y);
}

TEST_CASE("++ operator"){
    Fraction a(1,2), b(3,2);

    CHECK(++a == b);
    CHECK(a++ == 0.5);
}

TEST_CASE("-- operator"){
    Fraction a(3,1), b(2,1);

    CHECK(--a == b);
    CHECK(a++ == 3.0);
}

TEST_CASE("< operator"){
    Fraction a(3,1), b(2,1);

    CHECK((a<b)==false);
    CHECK((a<1.0)==false);
    CHECK((2.0<a)==true);
}

TEST_CASE("> operator"){
    Fraction a(2,3), b(1,3);

    CHECK((a>b)==true);
    CHECK((a>1.0)==false);
    CHECK((2.0>a)==true);
}

TEST_CASE("<= operator"){
    Fraction a(2,3), b(1,4), c(2,3);

    CHECK((a<=c)==true);
    CHECK((a<=1.0)==true);
    CHECK((2.0<=a)==false);
    CHECK((0.25<=b)==true);
}

TEST_CASE(">= operator"){
    Fraction a(2,3), b(1,4), c(2,3);

    CHECK((a>=c)==true);
    CHECK((a>=1.0)==false);
    CHECK((2.1>=a)==true);
    CHECK((0.25>=b)==true);
}

TEST_CASE("== operator"){
    Fraction a(2,3), b(1,4), c(2,3), d(4,6), e(3,12);

    CHECK(a==d);
    CHECK(a==c);
    CHECK((b==a)==false);
    CHECK(e==0.25);
    CHECK((0.25==b)==true);
    CHECK((b==0.75)==false);
}


