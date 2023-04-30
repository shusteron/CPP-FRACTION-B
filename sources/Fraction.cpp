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
    if(this->getNum()==0){
        this->setNum(0);
        this->setDenom(1);
    }
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

// Fraction + fraction.
Fraction Fraction::operator+(const Fraction &other){
    int num = this->getNum()*other.getDenom() + this->getDenom()*other.getNum();
    int denom = this->getDenom() * other.getDenom();
    Fraction result(num,denom);
    result.reduce();
    return result;
}

// Fraction + float.
Fraction Fraction::operator+(float number){
    Fraction other= this->convert(number);

    int num = this->getNum()*other.getDenom() + this->getDenom()*other.getNum();
    int denom = this->getDenom() * other.getDenom();
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
    int num = conv.getNum()*other.getDenom() + conv.getDenom()*other.getNum();
    int denom = conv.getDenom() * other.getDenom();
    Fraction result(num,denom);
    result.reduce();
    return result;
}

//------------------------------ OPERATOR "-" -------------------------------

// Fraction - fraction.
Fraction Fraction::operator-(const Fraction &other){
    int num = this->getNum()*other.getDenom() - this->getDenom()*other.getNum();
    int denom = this->getDenom() * other.getDenom();

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

    int num = this->getNum()*other.getDenom() - this->getDenom()*other.getNum();
    int denom = this->getDenom() * other.getDenom();
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
    int num = conv.getNum()*other.getDenom() - conv.getDenom()*other.getNum();
    int denom = conv.getDenom() * other.getDenom();
    Fraction result(num,denom);
    result.reduce();
    return result;
}

//------------------------------ OPERATOR * -------------------------------

// Fraction * fraction.
Fraction Fraction::operator*(const Fraction &other){
    int num = this->getNum() * other.getNum();
    int denom = this->getDenom() * other.getDenom();

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
    int num = this->getNum() * other.getNum();
    int denom = this->getDenom() * other.getDenom();
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
    int num = conv.getNum() * other.getNum();
    int denom = conv.getDenom() * other.getDenom();
    Fraction result(num,denom);
    result.reduce();
    return result;
}

//------------------------------ OPERATOR / -------------------------------

// Fraction / fraction.
Fraction Fraction::operator/(const Fraction &other){
    Fraction opposite(other.getDenom(), other.getNum());
    
    Fraction result = *this * opposite; 
    result.reduce();
    return result;
}

// Fraction / float.
Fraction Fraction::operator/(float number){
    Fraction opposite = convert(number);
    int num = opposite.getNum();
    int denom = opposite.getDenom();
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
    Fraction opposite(other.getDenom(),other.getNum());

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
bool Fraction::operator<(const Fraction &other){
    // Converting both fraction to float.
    float lvalue = (this->getNum()/this->getDenom())*1000;
    float rvalue = (other.getNum()/other.getDenom())*1000;
    return lvalue < rvalue;
}
// Fraction < float.
bool Fraction::operator<(float number){
    // Converting fraction to float.
    float lvalue = (this->getNum()/this->getDenom())*1000;
    return lvalue < number;
}

// Float < fraction.
bool operator<(float number, const Fraction& other){
    // Converting fraction to float.
    float rvalue = (other.getNum()/other.getDenom())*1000;
    return number < rvalue;
}

//------------------------------ OPERATOR > -------------------------------
// Fraction > fraction.
bool Fraction::operator>(const Fraction &other){
    // Converting both fraction to float.
    float lvalue =  static_cast<float>(this->getNum())/ static_cast<float>(this->getDenom());
    float rvalue =  static_cast<float>(other.getNum())/ static_cast<float>(other.getDenom());
    return lvalue > rvalue;
}

// Fraction > float.
bool Fraction::operator>(float number){
    // Converting fraction to float.
    float lvalue = (this->getNum()/this->getDenom())*1000;
    return lvalue > number;
}

// Float > fraction.
bool operator>(float number, const Fraction& other){
    // Converting fraction to float.
    float rvalue = (other.getNum()/other.getDenom())*1000;
    return number > rvalue;
}


//------------------------------ OPERATOR <= -------------------------------
// Fraction <= fraction.
bool Fraction::operator<=(const Fraction &other){
    // Converting both fraction to float.
    float lvalue =  static_cast<float>(this->getNum())/ static_cast<float>(this->getDenom());
    float rvalue =  static_cast<float>(other.getNum())/ static_cast<float>(other.getDenom());
    return lvalue <= rvalue;
}

// Fraction <= float.
bool Fraction::operator<=(float number){
    // Converting fraction to float.
    float lvalue =  static_cast<float>(this->getNum())/ static_cast<float>(this->getDenom());
    return lvalue <= number;
}

// Float <= fraction.
bool operator<=(float number, const Fraction& other){
    // Converting fraction to float.
    float rvalue =  static_cast<float>(other.getNum())/ static_cast<float>(other.getDenom());
    return number <= rvalue;
}


//------------------------------ OPERATOR >= -------------------------------
// Fraction >= fraction.
bool Fraction::operator>=(const Fraction &other){
    // Converting both fraction to float.
    float lvalue = (this->getNum()/this->getDenom())*1000;
    float rvalue = (other.getNum()/other.getDenom())*1000;
    return lvalue >= rvalue;
}

// Fraction >= float.
bool Fraction::operator>=(float number){
    // Converting fraction to float.
    float lvalue = (this->getNum()/this->getDenom())*1000;
    return lvalue >= number;
}

// Float >= fraction.
bool operator>=(float number, const Fraction& other){
    // Converting fraction to float.
    float rvalue = (other.getNum()/other.getDenom())*1000;
    return number >= rvalue;
}


//------------------------------ OPERATOR == -------------------------------
// Fraction == fraction
bool Fraction::operator==(const Fraction &other)const{
    // Temp fraction to reduce it.
    Fraction temp(other.getNum(),other.getDenom());
    temp.reduce();
    // Temp 'this' fraction to reduce it.
    Fraction this_temp(this->getNum(),this->getDenom());
    this_temp.reduce();
    return ((this_temp.getNum() == temp.getNum()) && (this_temp.getDenom() == temp.getDenom()));
}

// Fraction == float.
bool Fraction::operator==(float number){
    Fraction conv =this->convert(number);
    conv.reduce();
    this->reduce();
    return ((this->numerator == conv.getNum()) && (this->denominator == conv.getDenom()));
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
    Fraction temp(other.getNum(),other.getDenom());
    temp.reduce();
    return ((conv.getNum() == other.getNum()) && (conv.getDenom()==other.getDenom()));
}


//------------------------------ OPERATOR << -------------------------------
ostream& operator<< (ostream& output, const Fraction& f){
    Fraction temp(f.getNum(),f.getDenom());
    temp.reduce();
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
    if (denom == 0){
        throw invalid_argument(" Denominator cannot be zero.");
    }
    this->denominator=denom;
}


