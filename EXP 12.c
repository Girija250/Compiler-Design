#include <stdio.h>

int tempVar = 1;  // Temporary variable counter

// Function to generate three address code
void generateTAC(char op, char arg1[], char arg2[], char result[]) {
    printf("%s = %s %c %s\n", result, arg1, op, arg2);
}

int main() {
    char expr[] = "a + b * c - d"; // Example expression
    char t1[] = "T1", t2[] = "T2", t3[] = "T3";

    printf("Given Expression: %s\n", expr);
    printf("Three Address Code Representation:\n");

    // Step 1: Multiplication (b * c)
    generateTAC('*', "b", "c", t1);  // T1 = b * c

    // Step 2: Addition (a + T1)
    generateTAC('+', "a", t1, t2);   // T2 = a + T1

    // Step 3: Subtraction (T2 - d)
    generateTAC('-', t2, "d", t3);   // T3 = T2 - d

    printf("Final Result stored in: %s\n", t3);

    return 0;
}
