//
// addmix.cpp: add and multiply two numbers
//
#include<iostream>

int main()
{
  int a;
  double b;
  std::cout << "Enter an integer and a floating point number: ";
  std::cin >> a >> b;
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "the sum is " << a+b << std::endl;
  std::cout << "the product is " << a*b << std::endl;
}
