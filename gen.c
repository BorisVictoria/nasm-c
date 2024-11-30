#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float random_float(float min, float max) {
    return min + ((float)rand() / RAND_MAX) * (max - min);
}

int main() {
    int n;
    char filename[20];
    FILE *file;

    printf("Enter the number of rows to generate: ");
    scanf("%d", &n);

    sprintf(filename, "%d.txt", n);
    
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    srand(time(NULL));

    fprintf(file, "%d\n", n);
    
    for (int i = 0; i < n; i++) {
        float val1 = random_float(0.0, 300.0);
        float val2 = random_float(0.0, 300.0);
        float val3 = random_float(0.0, 10.0);
        fprintf(file, "%.2f, %.2f, %.2f\n", val1, val2, val3);
    }

    fclose(file);
    printf("Random floats have been written to %s\n", filename);

    return 0;
}
