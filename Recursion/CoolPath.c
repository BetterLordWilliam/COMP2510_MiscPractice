#include <stdio.h>
#include <stdlib.h>

/**
 * Function to compute the number of unique paths form the top left to the bottom right.
 * Grid size is n X m.
 * 
 * Param:   int n first dimension.
 * Param:   int m second dimension.
 * 
*/
int grid_paths(int n, int m) {

  // Base case
  if (n == 1 || m == 1) {
    return 1;
  }

  return grid_paths(n - 1, m) + grid_paths(n, m - 1);
}

int main(int argc, char* argv[]) {
  int n, m;
  n = atoi(argv[1]);
  m = atoi(argv[2]); 

  // Determine the answer to the problem
  printf("Unique paths for %d X %d grid are: %d\n", n, m, grid_paths(n, m));

  return 0;
}