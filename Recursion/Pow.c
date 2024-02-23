#include <stdio.h>
#include <stdlib.h>

/**
 * Function to determin the power of a number.
 * 
 * Param:   double x, the base
 * Param:   double n, the power
*/
double pow(double x, long n) { 
  if (x == 0)
    return 0;
  if (n == 0)
    return 1;
  if (n == 1)
    return x;
  return x * pow(x, n - 1);
}

/**
 * Main method
 * 
 * Param:   int argc argument count
 * Param:   char* argv[] arguments, starting 1
*/
int main(int argc, char* argv[]) {
  double num = atoi(argv[1]);
  long power = atoi(argv[2]);

  // Print the expression.
  printf("%lf^%ld\n", num, power);

  // Print the result.
  printf("Result %lf\n", pow(num, power));

  return 0;
}