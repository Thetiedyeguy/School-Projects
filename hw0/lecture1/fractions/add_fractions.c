/*
 * Adds fractions represented by pairs of integers.
 */

#include <stdlib.h>    /* provide function abs */

void add_fractions(int n1, int d1, int n2, int d2, int *n_ansp, int *d_ansp)
{
  int denom, numer,  sign_factor;

  /* Finds a common denominator	*/
  denom = d1 * d2;

  /* Computes numerator	*/
  numer = n1 * d2 + n2 * d1;

  /* Adjusts sign (at most, numerator should be negative)	*/
  if (numer * denom >= 0)
    sign_factor = 1;
  else
    sign_factor = -1;

  numer = sign_factor * abs(numer);
  denom = abs(denom);

  *n_ansp = numer;
  *d_ansp = denom;
}
