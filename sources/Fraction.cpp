#include "Fraction.hpp"
#include <ostream>
#include <iostream>

namespace ariel{}
using namespace std;

Fraction::Fraction(){
    this->numerator=0;
    this->denominator=1;
}

Fraction::Fraction(float number){
    if(number==0.0){
        this->numerator=0;
        this->denominator=1;
        return;
    }
    int numerator = number*1000;
    int denominator=1000;
    this->numerator = numerator;
    this->denominator = denominator;
}

Fraction::Fraction(int numerator, int denominator){
    if(denominator==0){
        throw invalid_argument("Denominator can not be zero.");
    }
    if(denominator < 0){
        this->numerator = -1 * numerator;
        this->denominator = -1 * denominator;
    }else{
        this->numerator = numerator;
        this->denominator = denominator;
    }
}
//------------------------------ PRIVATE METHODS --------------------------
int Fraction::gcd(int a, int b)const{
    a=abs(a);
    b=abs(b);
    if(a==0 || b==0){
        return 1;
    }
    if((a>=b)&&((a%b)==0)){
        return b;
    }else{
        return gcd(b,(a%b));
    }
}

void Fraction::reduce(){
    if(this->getNumerator()==0){
        this->setNum(0);
        this->setDenom(1);
    }
    int divide = this->gcd(this->getNumerator(), this->getDenominator());
    if(divide>1){
        this->setNum(this->getNumerator()/divide);
        this->setDenom(this->getDenominator()/divide);
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

// Fraction + fraction.
Fraction Fraction::operator+(const Fraction &other)const{
    int num = this->getNumerator()*other.getDenominator() + this->getDenominator()*other.getNumerator();
    int denom = this->getDenominator() * other.getDenominator();
    Fraction result(num,denom);
    result.reduce();
    return result;
}

// Fraction + float.
Fraction Fraction::operator+(float number){
    Fraction other= this->convert(number);

    int num = this->getNumerator()*other.getDenominator() + this->getDenominator()*other.getNumerator();
    int denom = this->getDenominator() * other.getDenominator();
    Fraction result(num,denom);
    result.reduce();
    return result;
    
}

// Float + Fraction.
Fraction operator+(float number, const Fraction& other){
    // Convert the float number to fraction obgect.
    Fraction conv(0,1);
    if(number != 0.0){
        int numerator = number*1000;
        int denominator=1000;
        conv.setNum(numerator);
        conv.setDenom(denominator);
        conv.reduce();
    }

    // Claculate.
    int num = conv.getNumerator()*other.getDenominator() + conv.getDenominator()*other.getNumerator();
    int denom = conv.getDenominator() * other.getDenominator();
    Fraction result(num,denom);
    result.reduce();
    return result;
}

//------------------------------ OPERATOR "-" -------------------------------

// Fraction - fraction.
Fraction Fraction::operator-(const Fraction &other)const{
    int num = this->getNumerator()*other.getDenominator() - this->getDenominator()*other.getNumerator();
    int denom = this->getDenominator() * other.getDenominator();

    if(num==0){
        Fraction result(0,1);
        return result;
    }
    Fraction result(num,denom);
    result.reduce();
    return result;
}
//  Fraction - float.
Fraction Fraction::operator-(float number){
    Fraction other= this->convert(number);

    int num = this->getNumerator()*other.getDenominator() - this->getDenominator()*other.getNumerator();
    int denom = this->getDenominator() * other.getDenominator();
    if(denom==0){
        Fraction result(0,1);
        return result;
    }
    Fraction result(num,denom);
    result.reduce();
    return result;
}

// Float - fraction.
Fraction operator-(float number, const Fraction& other){
    // Convert the float number to fraction obgect.
    Fraction conv(0,1);
    if(number != 0.0){
        int numerator = number*1000;
        int denominator=1000;
        conv.setNum(numerator);
        conv.setDenom(denominator);
        conv.reduce();
    }

    // Claculate.
    int num = conv.getNumerator()*other.getDenominator() - conv.getDenominator()*other.getNumerator();
    int denom = conv.getDenominator() * other.getDenominator();
    Fraction result(num,denom);
    result.reduce();
    return result;
}

//------------------------------ OPERATOR * -------------------------------

// Fraction * fraction.
Fraction Fraction::operator*(const Fraction &other)const{
    int num = this->getNumerator() * other.getNumerator();
    int denom = this->getDenominator() * other.getDenominator();

    Fraction result(num,denom);
    result.reduce();
    return result;
}

// Fraction * float.
Fraction Fraction::operator*(float number){
    if(number==0.0){
        Fraction result(0,1);
        return result;
    }

    Fraction other = convert(number);
    int num = this->getNumerator() * other.getNumerator();
    int denom = this->getDenominator() * other.getDenominator();
    Fraction result(num,denom);
    result.reduce();
    return result;
}

// Float * fraction.   
Fraction operator*(float number, const Fraction& other){
    if(number==0.0){
        Fraction result(0,1);
        return result;
    }

    // Convert the float number to fraction obgect.
    Fraction conv(0,1);
    if(number != 0.0){
        int numerator = number*1000;
        int denominator=1000;
        conv.setNum(numerator);
        conv.setDenom(denominator);
        conv.reduce();
    }
    // Calculate.
    int num = conv.getNumerator() * other.getNumerator();
    int denom = conv.getDenominator() * other.getDenominator();
    Fraction result(num,denom);
    result.reduce();
    return result;
}

//------------------------------ OPERATOR / -------------------------------

// Fraction / fraction.
Fraction Fraction::operator/(const Fraction &other)const{
    Fraction opposite(other.getDenominator(), other.getNumerator());
    
    Fraction result = *this * opposite; 
    result.reduce();
    return result;
}

// Fraction / float.
Fraction Fraction::operator/(float number){
    Fraction opposite = convert(number);
    int num = opposite.getNumerator();
    int denom = opposite.getDenominator();
    // Swap bwtween up & down.
    opposite.setNum(denom);
    opposite.setDenom(num);

    // Calculate.
    Fraction result = *this * opposite;
    result.reduce();
    return result;
}

// Float / fraction.
Fraction operator/(float number, const Fraction& other){
    // Convert the float number to fraction obgect.
    Fraction conv(0,1);
    if(number != 0.0){
        int numerator = number*1000;
        int denominator=1000;
        conv.setNum(numerator);
        conv.setDenom(denominator);
        conv.reduce();
    }
    // Initialize the opposite fraction.
    Fraction opposite(other.getDenominator(),other.getNumerator());

    // Calculate.
    Fraction result = conv*opposite;
    result.reduce();
    return result;
}


//------------------------------ OPERATOR "--" -------------------------------
//Postfix decrecment.(x--)
Fraction Fraction::operator--(int){
    Fraction copy = *this;
    this->numerator -= this->denominator;
    this->reduce();
    return copy;
}
//Pretfix decrecment.(--x)
Fraction& Fraction::operator--(){
    this->numerator -= this->denominator;
    return *this;
}

//------------------------------ OPERATOR ++ ---------------------------------
//Postfix increcment.(x++)
Fraction Fraction::operator++(int){
    Fraction copy = *this;
    this->numerator+=this->denominator;
    this->reduce();
    return copy;
    
}
//Pretfix increcment.(++x)
Fraction& Fraction::operator++(){
    this->numerator+=this->denominator;
    return *this;
}

//------------------------------ OPERATOR < ----------------------------------
// Fraction < fraction.
bool Fraction::operator<(const Fraction &other)const{
    // Converting both fraction to float.
    float lvalue = static_cast<float>(this->getNumerator())/ static_cast<float>(this->getDenominator());
    float rvalue = static_cast<float>(other.getNumerator())/ static_cast<float>(other.getDenominator());
    return lvalue < rvalue;
}
// Fraction < float.
bool Fraction::operator<(float number){
    // Converting fraction to float.
    float lvalue = static_cast<float>(this->getNumerator())/ static_cast<float>(this->getDenominator());

    return lvalue < number;
}

// Float < fraction.
bool operator<(float number, const Fraction& other){
    // Converting fraction to float.
    float rvalue = static_cast<float>(other.getNumerator())/ static_cast<float>(other.getDenominator());
    return number < rvalue;
}

//------------------------------ OPERATOR > -------------------------------
// Fraction > fraction.
bool Fraction::operator>(const Fraction &other)const{
    // Converting both fraction to float.
    float lvalue = static_cast<float>(this->getNumerator())/ static_cast<float>(this->getDenominator());
    float rvalue = static_cast<float>(other.getNumerator())/ static_cast<float>(other.getDenominator());
    return lvalue > rvalue;
}

// Fraction > float.
bool Fraction::operator>(float number){
    // Converting fraction to float.
    float lvalue = static_cast<float>(this->getNumerator())/ static_cast<float>(this->getDenominator());

    return lvalue > number;
}

// Float > fraction.
bool operator>(float number, const Fraction& other){
    // Converting fraction to float.
    float rvalue = static_cast<float>(other.getNumerator())/ static_cast<float>(other.getDenominator());
    return number > rvalue;
}

//------------------------------ OPERATOR <= -------------------------------
// Fraction <= fraction.
bool Fraction::operator<=(const Fraction &other)const{
    // Converting both fraction to float.
    float lvalue = static_cast<float>(this->getNumerator())/ static_cast<float>(this->getDenominator());
    float rvalue = static_cast<float>(other.getNumerator())/ static_cast<float>(other.getDenominator());
    return lvalue <= rvalue;
}

// Fraction <= float.
bool Fraction::operator<=(float number){
    // Converting fraction to float.
    float lvalue = static_cast<float>(this->getNumerator())/ static_cast<float>(this->getDenominator());
    return lvalue <= number;
}

// Float <= fraction.
bool operator<=(float number, const Fraction& other){
    // Converting fraction to float.
    float rvalue = static_cast<float>(other.getNumerator())/ static_cast<float>(other.getDenominator());
    return number <= rvalue;
}


//------------------------------ OPERATOR >= -------------------------------
// Fraction >= fraction.
bool Fraction::operator>=(const Fraction &other)const{
    // Converting both fraction to float.
    float lvalue = static_cast<float>(this->getNumerator())/ static_cast<float>(this->getDenominator());
    float rvalue = static_cast<float>(other.getNumerator())/ static_cast<float>(other.getDenominator());
    return lvalue >= rvalue;
}

// Fraction >= float.
bool Fraction::operator>=(float number){
    // Converting fraction to float.
    float lvalue = static_cast<float>(this->getNumerator())/ static_cast<float>(this->getDenominator());
    return lvalue >= number;
}

// Float >= fraction.
bool operator>=(float number, const Fraction& other){
    // Converting fraction to float.
    float rvalue = static_cast<float>(other.getNumerator())/ static_cast<float>(other.getDenominator());
    return number >= rvalue;
}


//------------------------------ OPERATOR == -------------------------------
// Fraction == fraction
bool Fraction::operator==(const Fraction &other)const{
    // Temp fraction to reduce it.
    Fraction temp(other.getNumerator(),other.getDenominator());
    temp.reduce();
    // Temp 'this' fraction to reduce it.
    Fraction this_temp(this->getNumerator(),this->getDenominator());
    this_temp.reduce();
    return ((this_temp.getNumerator() == temp.getNumerator()) && (this_temp.getDenominator() == temp.getDenominator()));
}

// Fraction == float.
bool Fraction::operator==(float number){
    Fraction conv =this->convert(number);
    conv.reduce();
    this->reduce();
    return ((this->numerator == conv.getNumerator()) && (this->denominator == conv.getDenominator()));
}

// Float == fraction.
bool operator==(float number, const Fraction& other){
    // Convert the float number to fraction obgect.
    Fraction conv(0,1);
    if(number != 0.0){
        int numerator = number*1000;
        int denominator=1000;
        conv.setNum(numerator);
        conv.setDenom(denominator);
        conv.reduce();
    }
    // Temp fraction to reduce it.
    Fraction temp(other.getNumerator(),other.getDenominator());
    temp.reduce();
    return ((conv.getNumerator() == other.getNumerator()) && (conv.getDenominator()==other.getDenominator()));
}


//------------------------------ OPERATOR << -------------------------------
ostream& operator<< (ostream& output, const Fraction& f){
    Fraction temp(f.getNumerator(),f.getDenominator());
    temp.reduce();
    return (output << f.numerator << '/' << f.denominator);
}

//------------------------------ OPERATOR >> -------------------------------
istream &operator>>(istream& input, Fraction& fraction) {
    int num, denom=0;
    input >> num;
    input >> denom;
    if(denom==0){
        throw runtime_error("Invalid input or not enough parameters.");
    } 
    fraction=Fraction(num,denom);
    return input;
}

//------------------------------ GETTERS & SETTERS -----------------------------------
int Fraction::getNumerator()const{
    return this->numerator;
}
int Fraction::getDenominator()const{
    return this->denominator;
}
void Fraction::setNum(int num){
    this->numerator = num;
}
void Fraction::setDenom(int denom){
    if (denom == 0){
        throw invalid_argument(" Denominator cannot be zero.");
    }
    this->denominator=denom;
}


