#include <stdio.h>
#include <string.h>

// Function to generate assembly-like instructions from Three Address Code
void generateAssembly(char op, char arg1[], char arg2[], char result[]) {
    switch (op) {
        case '+': printf("MOV R1, %s\nADD R1, %s\nMOV %s, R1\n", arg1, arg2, result); break;
        case '-': printf("MOV R1, %s\nSUB R1, %s\nMOV %s, R1\n", arg1, arg2, result); break;
        case '*': printf("MOV R1, %s\nMUL R1, %s\nMOV %s, R1\n", arg1, arg2, result); break;
        case '/': printf("MOV R1, %s\nDIV R1, %s\nMOV %s, R1\n", arg1, arg2, result); break;
        default: printf("Invalid Operation\n");
    }
}

int main() {
    // Example Three Address Code (TAC) for a = b + c
    char result[] = "T1";
    char arg1[] = "b";
    char arg2[] = "c";
    char op = '+';

    printf("Three Address Code (TAC):\n");
    printf("%s = %s %c %s\n", result, arg1, op, arg2);

    printf("\nGenerated Assembly Code:\n");
    generateAssembly(op, arg1, arg2, result);

    return 0;
}

