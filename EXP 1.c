#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
#define MAX_IDENTIFIER_LENGTH 31 
int isValidIdentifier(char *str) { 
    if (!isalpha(str[0]) && str[0] != '_') return 0; 
    for (int i = 1; str[i] != '\0'; i++) { 
        if (!isalnum(str[i]) && str[i] != '_') return 0; 
    } 
    return 1; 
} 
 
int isOperator(char ch) { 
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'); 
} 
 
void lexicalAnalyzer(char *code) { 
    char token[100]; 
    int index = 0; 
 
    for (int i = 0; code[i] != '\0'; i++) { 
        if (isalnum(code[i]) || code[i] == '_') { 
            index = 0; 
            while (isalnum(code[i]) || code[i] == '_') { 
                token[index++] = code[i++]; 
            } 
            token[index] = '\0'; 
            i--; 
 
            if (isValidIdentifier(token)) { 
                printf("Identifier: %s\n", token); 
            } else { 
                printf("Constant: %s\n", token); 
            } 
} else if (isOperator(code[i])) { 
printf("Operator: %c\n", code[i]); 
} 
} 
} 
int main() { 
char code[] = "int a = 5; b = a + 2;"; 
lexicalAnalyzer(code); 
return 0; 
}        
