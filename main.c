#include "bits/time.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void accel(float* cars, int* results, int length);

int main() {

  int length;
  scanf("%d", &length);
  printf("%d\n", length);
 
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

  struct timespec tic, toc;
  clock_gettime(CLOCK_MONOTONIC, &tic);

  accel(cars, results, length);

  clock_gettime(CLOCK_MONOTONIC, &toc);

  for (int i = 0; i < length; i++) {
    printf("Car %d: %d\n", i+1,  *(results + i));
  }
  
  printf("Elapsed: %ld nanoseconds\n", toc.tv_nsec - tic.tv_nsec);
  
  free(cars);
  free(results);

  return 0;
}

