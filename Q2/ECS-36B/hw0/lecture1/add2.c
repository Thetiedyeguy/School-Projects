//
// add.c: add two integers
//
#include<stdio.h>

int main()
{
  int a, b;
  printf("Enter two integers: ");
  scanf("%d %d",&a,&b);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("the sum is %d\n", a+b);
  return 0;
}
