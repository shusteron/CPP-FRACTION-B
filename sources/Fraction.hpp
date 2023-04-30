#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <stdio.h>
#include <ostream>

namespace ariel{}
using namespace std;

class Fraction{
    private:
        int numerator;
        int denominator;
        int gcd(int, int)const;
        void reduce();
        Fraction convert(float &number);

    public:
//------------------------------ CONSTRUCTORS -------------------------------
        Fraction();
        Fraction(float number);
        Fraction(int numerator, int denominator);
//------------------------------ OPERATOR + -------------------------------
        Fraction operator+(const Fraction& other) const;
        Fraction operator+(float number);
        friend Fraction operator+(float number, const Fraction& other);
//------------------------------ OPERATOR "-" -------------------------------
        Fraction operator-(const Fraction& other) const;
        Fraction operator-(float number);
        friend Fraction operator-(float number, const Fraction& other);
//------------------------------ OPERATOR * -------------------------------
        Fraction operator*(const Fraction& other)const;
        Fraction operator*(float number);
        friend Fraction operator*(float number, const Fraction& other);
//------------------------------ OPERATOR / -------------------------------
        Fraction operator/(const Fraction& other)const;
        Fraction operator/(float number);
        friend Fraction operator/(float number, const Fraction& other);
//------------------------------ OPERATOR "--" -------------------------------
        Fraction operator--(int);
        Fraction& operator--();
//------------------------------ OPERATOR ++ -------------------------------
        Fraction operator++(int);
        Fraction& operator++();
//------------------------------ OPERATOR < -------------------------------
        bool operator<(const Fraction& other)const;
        bool operator<(float number);
        friend bool operator<(float number, const Fraction& other);
//------------------------------ OPERATOR > -------------------------------
        bool operator>(const Fraction& other)const;
        bool operator>(float number);
        friend bool operator>(float number, const Fraction& other);
//------------------------------ OPERATOR <= -------------------------------
        bool operator<=(const Fraction& other)const;
        bool operator<=(float number);
        friend bool operator<=(float number, const Fraction& other);
//------------------------------ OPERATOR >= -------------------------------
        bool operator>=(const Fraction& other)const;
        bool operator>=(float number);
        friend bool operator>=(float number, const Fraction& other);
//------------------------------ OPERATOR == -------------------------------
        bool operator==(const Fraction&)const;
        bool operator==(float number);
        friend bool operator==(float number, const Fraction& other);
//------------------------------ OPERATOR << -------------------------------
        friend ostream& operator<< (ostream& output, const Fraction& c);
//------------------------------ OPERATOR >> -------------------------------
        friend istream& operator>>(istream& input, Fraction& fraction);
//------------------------------ GETTERS & SETTERS -------------------------------
        int getNumerator()const;
        int getDenominator()const;
        void setNum(int num);
        void setDenom(int denom);

};
#endif