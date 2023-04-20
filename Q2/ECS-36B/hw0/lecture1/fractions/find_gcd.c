/* Finds greatest common divisor of two integers */

#include <stdio.h>

int find_gcd (int n1, int n2)
{
  int gcd, remainder;

  /* Euclid's algorithm */
  remainder = n1 % n2;
  while ( remainder != 0 )
  {
    n1 = n2;
    n2 = remainder;
    remainder = n1 % n2;
  }
  gcd = n2;

  return (gcd);
}
