/* Multiplies fractions represented by pairs of integers. */
void multiply_fractions(int n1, int d1,
                        int n2, int d2,
                        int *n_ansp, int *d_ansp)
{
  /* Defines output arguments	*/
  *n_ansp = n1*n2;
  *d_ansp = d1*d2;
}
