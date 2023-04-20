

//Josiah Johnson 919670770

#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction(int num, int den){
    numerator = num;
    denominator = den;
    int remainder;
    int n1 = num;
    int n2 = den;
    remainder = n1 % n2;
    while(remainder != 0){
        n1 = n2;
        n2 = remainder;
        remainder = n1 % n2;
    }
    if(n2 < 0){
        n2 = n2 * -1;
    }
    numerator = numerator / n2;
    denominator = denominator / n2;
}
Fraction::Fraction(int num){
    numerator = num;
    denominator = 1;
}
Fraction::Fraction(void){
    numerator = 1;
    denominator = 1;
}
int Fraction::getNum(void) const{
    return numerator;
}
int Fraction::getDen(void) const{
    return denominator;
}
void Fraction::operator=(int number){
    numerator = number;
    denominator = 1;
}
const Fraction operator+(const Fraction& f1, const Fraction& f2){
    Fraction temp((f1.numerator * f2.denominator) + (f2.numerator * f1.denominator), f1.denominator * f2.denominator);
    return temp;
}
const Fraction operator+(const int n, const Fraction& f){
    Fraction temp(n);
    return f + temp;
}
const Fraction operator+(const Fraction& f, const int n){
    Fraction temp(n);
    return f + temp;
}
const Fraction operator-(const Fraction& f1, const Fraction& f2){
    Fraction temp((f1.numerator * f2.denominator) - (f2.numerator * f1.denominator), f1.denominator * f2.denominator);
    return temp;
}
const Fraction operator-(const int n, const Fraction& f){
    Fraction temp(n);
    return temp - f;
}
const Fraction operator-(const Fraction& f, const int n){
    Fraction temp(n);
    return f - temp;
}
const Fraction operator-(const Fraction& f){
    Fraction temp(f.numerator * -1, f.denominator);
    return temp;
}
const Fraction operator*(const Fraction& f1, const Fraction& f2){
    Fraction temp(f1.numerator * f2.numerator, f2.denominator * f1.denominator);
    return temp;
}
const Fraction operator*(const int n, const Fraction& f){
    Fraction temp(n);
    return temp * f;
}
const Fraction operator*(const Fraction& f, const int n){
    Fraction temp(n);
    return temp * f;
}
const Fraction operator/(const Fraction& f1, const Fraction& f2){
    Fraction temp(f1.numerator * f2.denominator, f2.numerator * f1.denominator);
    if(temp.getDen() == 0){
        throw invalid_argument("Exception zero denominator");
    }
    return temp;
}
const Fraction operator/(const Fraction& f, const int n){
    Fraction temp(n);
    return f / temp;
}
const Fraction operator/(const int n, const Fraction& f){
    Fraction temp(n);
    return temp / f;
}



std::ostream& operator << (std::ostream& os, const Fraction& f){
    if(f.denominator == 1){
        os << f.numerator;
    }else{
        os << f.numerator << '/' << f.denominator;
    }
    return os;
}
