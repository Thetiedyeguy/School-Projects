//
// testFraction.cpp
//
// DO NOT MODIFY THIS FILE
//

#include "Fraction.h"
#include<iostream>
using namespace std;
void print_fraction(const Fraction& f)
{
  cout << " print_fraction: " << f.getNum() << "/" << f.getDen() << endl;
}
int main()
{
  Fraction w;
  w = 4;
  Fraction x(4,6);
  Fraction y(5,6);
  Fraction z(0);
  cout << " w = " << w << endl;
  cout << " x = " << x << endl;
  cout << " y = " << y << endl;
  cout << " z = " << z << endl;

  cout << " x+y = " << x + y << endl;
  cout << " x-y = " << x - y << endl;
  cout << " x*y = " << x * y << endl;
  cout << " x/y = " << x / y << endl;

  cout << " -x = " << -x << endl;
  cout << " x+2 = " << x + 2 << endl;
  cout << " 2+x = " << 2 + x << endl;
  cout << " x-2 = " << x - 2 << endl;
  cout << " 2-x = " << 2 - x << endl;
  cout << " 2*x = " << 2 * x << endl;
  cout << " x*2 = " << x * 2 << endl;
  cout << " x/2 = " << x / 2 << endl;
  cout << " 2/x = " << 2 / x << endl;

  cout << " w+x+y = " << w + x + y << endl;

  print_fraction(y);

  try
  {
    cout << " x / z = " << x / z << endl;
  }
  catch ( invalid_argument& e )
  {
    cout << "Exception: " << e.what() << endl;
  }
  cout << " 2 * ( x + y ) = " << 2 * ( x + y ) << endl;
  Fraction u(12,18);
  print_fraction(u);
}
