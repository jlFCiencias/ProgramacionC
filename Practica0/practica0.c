/*
 Jose Luis Torres Rodriguez
 Practica 0
*/
#include<stdio.h>

main()
{
  int n;

  for (n=1; n<=30; n++){
    if ((n%3)==0 && (n%5)==0)
      printf("FizzBuzz\n");
    else
      if ((n%3)==0)
	printf("Fizz\n");
      else
	if ((n%5)==0)
	  printf("Buzz\n");
        else
	  printf("%d\n", n);
  }
}
