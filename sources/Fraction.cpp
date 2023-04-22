#include "Fraction.hpp"
#include <ostream>
#include <iostream>



namespace ariel{}
using namespace std;

Fraction::Fraction(){
    this->numerator=0;
    this->denominator=1;
}

Fraction::Fraction(int numerator, int denominator){
    if(denominator==0){
        throw invalid_argument("Denominator can not be zero.");
    }
    this->numerator=numerator;
    this->denominator=denominator;
}
//------------------------------ PRIVATE METHODS --------------------------
int Fraction::gcd(int a, int b){
    a=abs(a);
    b=abs(b);
    if((a>=b)&&((a%b)==0)){
        return b;
    }else{
        return gcd(b,(a%b));
    }
}

void Fraction::reduce(){
    int divide = this->gcd(this->getNum(), this->getDenom());
    if(divide>1){
        this->setNum(this->getNum()/divide);
        this->setDenom(this->getDenom()/divide);
    }
}

Fraction Fraction::convert(float &number){
    if(number==0.0){
        Fraction result(0,1);
        return result;
    }
    int numerator = number*1000;
    int denominator=1000;
    Fraction result(numerator,denominator);
    result.reduce();
    return result;
}

//------------------------------ OPERATOR + ----------------------------------
Fraction Fraction::operator+(const Fraction &other){
    int num = this->getNum()*other.getDenom() + this->getDenom()*other.getNum();
    int denom = this->getDenom() * other.getDenom();
    Fraction result(num,denom);
    result.reduce();
    return result;
}

Fraction Fraction::operator+(float number){
    Fraction other= this->convert(number);

    int num = this->getNum()*other.getDenom() + this->getDenom()*other.getNum();
    int denom = this->getDenom() * other.getDenom();
    Fraction result(num,denom);
    result.reduce();
    return result;
    
}
Fraction operator+(float number, const Fraction& other){
    // Convert the float number to fraction obgect.
    int numerator = number*1000;
    int denominator=1000;
    Fraction conv(numerator,denominator);
    conv.reduce();

    // Claculate.
    int num = conv.getNum()*other.getDenom() + conv.getDenom()*other.getNum();
    int denom = conv.getDenom() * other.getDenom();
    Fraction result(num,denom);
    result.reduce();
    return result;
}

//------------------------------ OPERATOR "-" -------------------------------
Fraction Fraction::operator-(const Fraction &other){
    int num = this->getNum()*other.getDenom() - this->getDenom()*other.getNum();
    int denom = this->getDenom() * other.getDenom();
    Fraction result(num,denom);
    result.reduce();
    return result;
}
//  Fraction - float.
Fraction Fraction::operator-(float number){
    Fraction other= this->convert(number);
    cout << other << endl;

    int num = this->getNum()*other.getDenom() - this->getDenom()*other.getNum();
    int denom = this->getDenom() * other.getDenom();
    Fraction result(num,denom);
    result.reduce();
    return result;
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
    Fraction copy = *this;
    this->numerator+=this->denominator;
    return copy;
    
}
//Pretfix increcment.
Fraction Fraction::operator++(){
    this->numerator+=this->denominator;
    return *this;
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
//------------------------------ GETTERS & SETTERS -----------------------------------
int Fraction::getNum()const{
    return this->numerator;
}
int Fraction::getDenom()const{
    return this->denominator;
}
void Fraction::setNum(int num){
    this->numerator = num;
}
void Fraction::setDenom(int denom){
    this->denominator=denom;
}


