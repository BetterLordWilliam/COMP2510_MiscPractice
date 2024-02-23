#include <stdio.h>
#include <stdlib.h>

/**
 * Aparently cringe slow fibonacci.
 * Fib -> each term is the sum of the previous terms.
 * 
 * Param:   int n, term n.
*/
int fib(int n) {
  if (n <= 1)
    return n;
  return fib(n-1) + fib(n-2);
}

/**
 * Cooler algorithm.
 * 
 * Param    int n, term n
*/
int fibC(int n) {

}

int main() {
  int n = 10;

  // Show cool test
  printf("%d\n", fib(n));
  printf("%d\n", fibC(n));

  return 0;
}