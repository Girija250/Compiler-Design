#include <stdio.h>

int main() {
    // Example expression
    int a = 5, b = 2, c = 3, d = 4;
    int result;

    // Displaying the original expression
    printf("Given Expression: %d + %d * %d - %d / %d\n", a, b, c, d, b);

    // Step-by-step evaluation
    int step1 = b * c;   // Multiplication first
    printf("Step 1: %d * %d = %d\n", b, c, step1);

    int step2 = d / b;   // Division second
    printf("Step 2: %d / %d = %d\n", d, b, step2);

    int step3 = a + step1; // Addition third
    printf("Step 3: %d + %d = %d\n", a, step1, step3);

    result = step3 - step2; // Subtraction last
    printf("Step 4: %d - %d = %d\n", step3, step2, result);

    printf("Final Result: %d\n", result);
    
    return 0;
}

