#include <stdio.h> 
int isOperator(char ch) { 
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'); 
} 
void analyzeOperators(char *code) { 
    for (int i = 0; code[i] != '\0'; i++) { 
        if (isOperator(code[i])) { 
            printf("Operator: %c\n", code[i]); 
        } 
    } 
} 
int main() { 
    char code[] = "a = b + c * d / e - f;"; 
    analyzeOperators(code); 
    return 0; 
}
