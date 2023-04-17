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

    public:
        Fraction();
        Fraction(int numerator, int denominator);
//------------------------------ OPERATOR + -------------------------------
        Fraction operator+(const Fraction& other);
        Fraction operator+(float number);
        friend Fraction operator+(float number, const Fraction& other){
                return Fraction();
        }
//------------------------------ OPERATOR "-" -------------------------------
        Fraction operator-(const Fraction& other);
        Fraction operator-(float number);
        friend Fraction operator-(float number, const Fraction& other){
                return Fraction();
        }
//------------------------------ OPERATOR * -------------------------------
        Fraction operator*(const Fraction& other);
        Fraction operator*(float number);
        friend Fraction operator*(float number, const Fraction& other){
                return Fraction();
        }
//------------------------------ OPERATOR / -------------------------------
        Fraction operator/(const Fraction& other);
        Fraction operator/(float number);
        friend Fraction operator/(float number, const Fraction& other){
                return Fraction();
        }
//------------------------------ OPERATOR "--" -------------------------------
        Fraction operator--(int);
        Fraction operator--();
//------------------------------ OPERATOR ++ -------------------------------
        Fraction operator++(int);
        Fraction operator++();
//------------------------------ OPERATOR < -------------------------------
        bool operator<(const Fraction& other);
        bool operator<(float number);
        friend bool operator<(float number, const Fraction& other){
                return false;
        }
//------------------------------ OPERATOR > -------------------------------
        bool operator>(const Fraction& other);
        bool operator>(float number);
        friend bool operator>(float number, const Fraction& other){
                return false;
        }
//------------------------------ OPERATOR <= -------------------------------
        bool operator<=(const Fraction& other);
        bool operator<=(float number);
        friend bool operator<=(float number, const Fraction& other){
                return false;
        }
//------------------------------ OPERATOR >= -------------------------------
        bool operator>=(const Fraction& other);
        bool operator>=(float number);
        friend bool operator>=(float number, const Fraction& other){
                return false;
        }
//------------------------------ OPERATOR == -------------------------------
        bool operator==(const Fraction& other);
        bool operator==(float number);
        friend bool operator==(float number, const Fraction& other){
                return false;
        }
//------------------------------ OPERATOR << -------------------------------
        friend ostream& operator<< (ostream& output, const Fraction& c);
//------------------------------ GETTERS -------------------------------
        int getNum();
        int getDenom();

};
#endif