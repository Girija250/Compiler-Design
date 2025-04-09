#include <stdio.h> 
#include <string.h> 
int isComment(char *line) { 
if (strncmp(line, "//", 2) == 0) return 1; 
    if (strncmp(line, "/*", 2) == 0) return 2; 
    return 0; 
} 
 
void analyzeComments(char *code) { 
    for (int i = 0; code[i] != '\0'; i++) { 
        if (code[i] == '/' && code[i + 1] == '/') { 
            printf("Single-line comment detected\n"); 
            return; 
        } 
        if (code[i] == '/' && code[i + 1] == '*') { 
            printf("Multi-line comment detected\n"); 
            return; 
        } 
    } 
} 
 
int main() { 
    char code[] = "/* This is a multi-line comment */\n// This is a single-line comment"; 
    analyzeComments(code); 
    return 0; 
}
