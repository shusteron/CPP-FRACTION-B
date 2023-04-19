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
//------------------------------ PRIVATE METHODS --------------------------
int Fraction::gcd(int a, int b){
     while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduse(Fraction& f){
    int devide = this->gcd(f.getNum(), f.getDenom());

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
Fraction operator-(float number, const Fraction& other){
    return Fraction();
}

//------------------------------ OPERATOR * -------------------------------
Fraction Fraction::operator*(const Fraction &other){
    return Fraction();
}

Fraction Fraction::operator*(float number){
    return Fraction();
}
Fraction operator*(float number, const Fraction& other){
    return Fraction();
}

//------------------------------ OPERATOR / -------------------------------
Fraction Fraction::operator/(const Fraction &other){
    return Fraction();
}
Fraction Fraction::operator/(float number){
    return Fraction();
}
Fraction operator/(float number, const Fraction& other){
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
    this->numerator+=this->denominator;
    return Fraction();
    //return *this;
}

//------------------------------ OPERATOR < -------------------------------
bool Fraction::operator<(const Fraction &other){
    return false;
}
bool Fraction::operator<(float number){
    return false;
}
bool operator<(float number, const Fraction& other){
    return false;
}

//------------------------------ OPERATOR > -------------------------------
bool Fraction::operator>(const Fraction &other){
    return false;
}
bool Fraction::operator>(float number){
    return false;
}
bool operator>(float number, const Fraction& other){
    return false;
}


//------------------------------ OPERATOR <= -------------------------------
bool Fraction::operator<=(const Fraction &other){
    return false;
}
bool Fraction::operator<=(float number){
    return false;
}
bool operator<=(float number, const Fraction& other){
    return false;
}


//------------------------------ OPERATOR >= -------------------------------
bool Fraction::operator>=(const Fraction &other){
    return false;
}
bool Fraction::operator>=(float number){
    return false;
}
bool operator>=(float number, const Fraction& other){
    return false;
}


//------------------------------ OPERATOR == -------------------------------
bool Fraction::operator==(const Fraction &other) const{
    return ((this->numerator == other.numerator)&& (this->denominator == other.denominator));
}
bool Fraction::operator==(float number){
    return false;
}
bool operator==(float number, const Fraction& other){
    return false;
}


//------------------------------ OPERATOR << -------------------------------
ostream& operator<< (ostream& output, const Fraction& f){
    return (output << f.numerator << '/' << f.denominator);
}
//------------------------------ GETTERS -----------------------------------
int Fraction::getNum(){
    return this->numerator;
}
int Fraction::getDenom(){
    return this->denominator;
}


