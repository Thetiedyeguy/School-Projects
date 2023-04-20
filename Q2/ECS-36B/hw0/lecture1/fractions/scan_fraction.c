/*
 * Gets and returns a valid fraction as its result
 * A valid fraction is of this form: integer/positive integer
 */

#include <stdio.h>

void scan_fraction(int *nump, int *denomp)
{
  char slash;
  int  status, error;
  char discard;

  do
  {
    error = 0;
    printf("Enter a fraction as two integers separated by a slash > ");

    status = scanf("%d%c%d",nump,&slash,denomp);

    /* status indicating number of valid values obtained */
    if (status < 3)
    {
      error = 1;
      printf("Invalid-please read directions carefully\n");
    }
    else if (slash != '/')
    {
      error = 1;
      printf("Invalid-separate numerator and denominator\n");
      printf("by a slash (/)\n");
    }
    else if (*denomp <= 0)
    {
      error = 1;
      printf("Invalid-denominator must be positive\n");
    }

    /* Discard extra input characters 	*/
    do
    {
      scanf("%c", &discard);
    } while (discard != '\n');

  } while (error);
}
