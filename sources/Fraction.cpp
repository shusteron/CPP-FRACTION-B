#include "Fraction.hpp"
#include <ostream>


namespace ariel{}
using namespace std;

Fraction::Fraction(){
    this->numerator=1;
    this->denominator=1;
}

Fraction::Fraction(int numerator, int denominator){
    this->numerator=numerator;
    this->denominator=denominator;
}
//------------------------------ OPERATOR + -------------------------------
Fraction Fraction::operator+(const Fraction &other){
    return Fraction();
}

Fraction Fraction::operator+(float number){
    return Fraction();
}

Fraction operator+(float number, const Fraction& other){
    return Fraction();
}

//------------------------------ OPERATOR "-" -------------------------------
Fraction Fraction::operator-(const Fraction &other){
    return Fraction();
}
Fraction Fraction::operator-(float number){
    return Fraction();
}

Fraction operator-(float number, const Fraction &other)
{
    return Fraction();
}

//------------------------------ OPERATOR * -------------------------------
Fraction Fraction::operator*(const Fraction &other){
    return Fraction();
}

Fraction Fraction::operator*(float number){
    return Fraction();
}

Fraction operator*(float number,const Fraction &other){
    return Fraction();
}

//------------------------------ OPERATOR / -------------------------------

Fraction Fraction::operator/(const Fraction &other){
    return Fraction();
}
Fraction Fraction::operator/(float number){
    return Fraction();
}

Fraction operator/(float number,const Fraction &other){
    return Fraction();
}

//------------------------------ OPERATOR "--" -------------------------------
Fraction Fraction::operator--(int){
    return Fraction();
}
Fraction Fraction::operator--(){
    return Fraction();
}

//------------------------------ OPERATOR ++ -------------------------------
//Postfix increcment.
Fraction Fraction::operator++(int){
    this->numerator+=this->denominator;
    return *this;
}
//Pretfix increcment.
Fraction Fraction::operator++(){
    return Fraction();
}

//------------------------------ OPERATOR < -------------------------------
bool Fraction::operator<(const Fraction &other){
    return true;
}


//------------------------------ OPERATOR > -------------------------------
bool Fraction::operator>(const Fraction &other){
    return true;
}


//------------------------------ OPERATOR <= -------------------------------
bool Fraction::operator<=(const Fraction &other){
    return true;
}


//------------------------------ OPERATOR >= -------------------------------
bool Fraction::operator>=(const Fraction &other){
    return true;
}

//------------------------------ OPERATOR == -------------------------------
bool Fraction::operator==(const Fraction &other){
    return true;
}

//------------------------------ OPERATOR << -------------------------------
ostream& operator<< (ostream& output, const Fraction& f){
    return (output << f.numerator << '/' << f.denominator);
}

