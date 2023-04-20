
//Josiah Johnson 919670770

#ifndef FRACTION_H
#define FRACTION_H

#include<iostream>
#include<stdexcept>
using namespace std;

class Fraction
{
  private:
      int numerator;
      int denominator;

  public:
      Fraction(int num, int den);
      Fraction(int num);
      Fraction(void);
      int getNum(void) const;
      int getDen(void) const;
      void operator=(int number);
      friend const Fraction operator+(const Fraction& f1, const Fraction& f2);
      friend const Fraction operator+(const int n, const Fraction& f);
      friend const Fraction operator+(const Fraction& f, const int n);
      friend const Fraction operator-(const Fraction& f1, const Fraction& f2);
      friend const Fraction operator-(const Fraction& f, const int n);
      friend const Fraction operator-(const int n, const Fraction& f);
      friend const Fraction operator-(const Fraction& f);
      friend const Fraction operator*(const Fraction& f1, const Fraction& f2);
      friend const Fraction operator*(const int n, const Fraction& f);
      friend const Fraction operator*(const Fraction& f, const int n);
      friend const Fraction operator/(const Fraction& f1, const Fraction& f2);
      friend const Fraction operator/(const Fraction& f, const int n);
      friend const Fraction operator/(const int n, const Fraction& f);
      friend std::ostream& operator << (std::ostream& os, const Fraction& f);
};
#endif
