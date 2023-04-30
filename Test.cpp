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
    Fraction a(1,2), b(2,4), x(3,2), y(5,2), z(-1,2), w(-1,2),
        k(-1,1), s(3,4), g(2,5), f(-7,4);

    CHECK((a+b)==1.0);
    CHECK((1.0+a)==x);
    CHECK((x+1.0)==y);
    
}

TEST_CASE("- operator"){
    Fraction a(1,2), b(2,4),c(5,3), x(1,2), y(2,3), w(-1,2),
        d(1,1), j(17,-10), g(3,2), r(0,1);
    
    CHECK((a-b)==r);
    CHECK((1.0-a)==x);
    CHECK((c-1.0)==y);
    CHECK((a-w)==d);
    CHECK((-1.2-a)==j);
    CHECK((a-(-1.0))==g);
}

TEST_CASE("* operator"){
    Fraction a(1,2), b(2,4),c(5,3),
     x(5,6), y(0,1) ,w(-1,2), z(-1,4), k(1,4);

    CHECK((a*c)==x);
    CHECK((0.0*a)==y);
    CHECK((a*0.0)==y);
    CHECK((a*2.0)==1.0);
    CHECK((a*w)==z);
    CHECK((w*w)==k);
    CHECK((a*(-1.0))==w);
    CHECK((-1.0*w)==a);
}

TEST_CASE("/ operator"){
    Fraction a(1,2), b(2,4),c(5,3),
    x(3,2), y(5,9), z(-1,4);

    CHECK((b/a)==1.0);
    CHECK((2.5/c)==x);
    CHECK((c/3.0)==y);
    CHECK((a/(-0.5))==-1.0);
    CHECK(((-0.5)/a)==-1.0);
    CHECK((a/z)==-2.0);
}

TEST_CASE("++ operator"){
    Fraction a(1,2), b(3,2), c(-1,2), x(1,2);

    CHECK(++a == b);
    CHECK(++c==x);
    CHECK(x++ == 0.5);
}

TEST_CASE("-- operator"){
    Fraction a(3,1), b(2,1), c(1,2), d(3,1);

    CHECK(--a == b);
    CHECK(--c==-0.5);
    CHECK(d++ == 3.0);
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
    Fraction a(2,3), b(1,4), c(2,3),
        d(4,6), e(3,12);

    CHECK(a==d);
    CHECK(a==c);
    CHECK((b==a)==false);
    CHECK(e==0.25);
    CHECK((0.25==b)==true);
    CHECK((b==0.75)==false);
}


