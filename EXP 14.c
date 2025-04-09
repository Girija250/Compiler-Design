#include <stdio.h>

int main() {
    int a = 5, b = 3, c = 2, x, y, z;

    // Given expression before optimization:
    x = (a * b) + (a * b);  // Common subexpression: (a * b)
    y = (b + c) * (a * b);  // Common subexpression: (a * b)
    z = (a * b) + c;        // Common subexpression: (a * b)

    printf("Before Optimization:\n");
    printf("x = (a * b) + (a * b) = %d\n", x);
    printf("y = (b + c) * (a * b) = %d\n", y);
    printf("z = (a * b) + c = %d\n", z);

    // Optimized Code: Compute (a * b) once and reuse
    int temp = a * b;
    x = temp + temp;
    y = (b + c) * temp;
    z = temp + c;

    printf("\nAfter Optimization:\n");
    printf("x = temp + temp = %d\n", x);
    printf("y = (b + c) * temp = %d\n", y);
    printf("z = temp + c = %d\n", z);

    return 0;
}

