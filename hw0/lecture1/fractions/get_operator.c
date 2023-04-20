/*
 * Gets and returns a valid arithmetic operator.  Skips over newline
 * characters and permits re-entry of operator in case of error.
 */

#include <stdio.h>

char get_operator(void)
{
  char op;

  printf("Enter an arithmetic operator (+,-,*, or /)> ");
  for ( scanf("%c", &op);
        op != '+'  &&  op != '-'  && op != '*'  &&  op != '/';
        scanf("%c", &op) )
  {
    if (op != '\n')
      printf("%c invalid, reenter operator (+,-, *,/)> ", op);
  }
  return (op);
}
