#include <stdio.h>
#include <stdlib.h>

/**
 * Recursive function computes the sum of a number to n.
 * 
 * Param: int n number we want the sum of
*/
int sum(int n) {
  // Base case
  if (n == 0)
    return 0;
  else {
    return n + sum(n-1);
  }
} // so cute!

int main(int argc, char* argv[]) {
  int n = atoi(argv[1]);
  printf("Sum of nonnegative integers up to %d is: %d\n", n, sum(n));
}