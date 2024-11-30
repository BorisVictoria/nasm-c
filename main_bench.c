#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void accel(float* cars, int* results, int length);

int main() {

  int length;
  scanf("%d", &length);
 
  float* cars = (float*)malloc(length * 3 * sizeof(float));
  int* results = (int*)malloc(length * sizeof(int));

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        scanf("%f", cars + (i * 3) + j);
      } else {
        scanf(",%f", cars + (i * 3) + j);
      }
    }
  }

  clock_t tic = clock();

  accel(cars, results, length);

  clock_t toc = clock();

  printf("%f", ((double)(toc-tic) / CLOCKS_PER_SEC) * 1000);
  
  free(cars);
  free(results);

  return 0;
}

