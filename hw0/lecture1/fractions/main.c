/*
 * Example of procedural programming
 *
 * Adds, subtracts, multiplies and divides common fractions, displaying
 * results in reduced form.
 *
 */


#include <stdio.h>


/* Function prototypes */
void scan_fraction(int *nump, int *denomp);
char get_operator(void);
void add_fractions(int n1, int d1, int n2, int d2, int *n_ansp, int *d_ansp);
void multiply_fractions(int n1, int d1, int n2, int d2,
                        int *n_ansp, int *d_ansp);
void reduce_fraction(int *nump, int *denomp);

int main(void)
{
  int  n1, d1, n2, d2, n_ans, d_ans;
  char op, again;

  do
  {
    /* Gets a fraction problem */
    scan_fraction(&n1, &d1);
    op = get_operator();
    scan_fraction(&n2, &d2);

    /* Computes the result  */
    switch (op)
    {
      case '+':
            add_fractions(n1, d1, n2, d2, &n_ans, &d_ans);
            break;

      case '-':
            add_fractions(n1, d1, -n2, d2, &n_ans, &d_ans);
            break;

      case '*':
            multiply_fractions(n1, d1, n2, d2, &n_ans, &d_ans);
            break;

      case '/':
            multiply_fractions(n1, d1, d2, n2, &n_ans, &d_ans);
    }

    /* reduce fraction by the gcd */
    reduce_fraction(&n_ans, &d_ans);

    /* Displays result */
    printf("\n%d/%d %c %d/%d = %d/%d", n1, d1, op, n2, d2, n_ans, d_ans);
    /*  Do another problem */
    printf("\nDo another problem? (y/n)> ");
    scanf(" %c", &again);

  } while (again == 'y'  ||  again == 'Y');

  return (0);
}
