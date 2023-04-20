#include "Angle.h"
#include <iostream>
using namespace std;

int main()
{
  Angle a;
  a.print();
  a.change(15);   a.print();
  a.change(10);   a.print();
  a.change(-120); a.print();
  a.change(-5);   a.print();
  a.change(0);    a.print();
  a.change(60);   a.print();
  a.change(-135); a.print();
  a.change(1);    a.print();
  a.change(-1);   a.print();
  a.change(1);    a.print();
  a.change(-10);  a.print();
  a.change(50);   a.print();
  a.change(150);  a.print();
  a.change(-30);  a.print();

  a.change(10);
  cout << a.get() << endl;
}
