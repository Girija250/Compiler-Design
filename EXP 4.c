#include <stdio.h> 
#include <ctype.h> 
 
void countWhitespaces(char *code) { 
    int whitespaceCount = 0, newlineCount = 0; 
 
    for (int i = 0; code[i] != '\0'; i++) { 
        if (isspace(code[i])) { 
            if (code[i] == '\n') newlineCount++; 
            else whitespaceCount++; 
        } 
    } 
 
    printf("Whitespaces: %d, Newlines: %d\n", whitespaceCount, newlineCount); 
} 
 
int main() { 
    char code[] = "int a = 5; \n b = a + 2; \n"; 
    countWhitespaces(code); 
    return 0; 
}
