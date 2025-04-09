#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char nonTerminal, char alpha[], char beta[]) {
    printf("Grammar after eliminating left recursion:\n");
    printf("%c -> %s%c'\n", nonTerminal, beta, nonTerminal);
    printf("%c' -> %s%c' | e\n", nonTerminal, alpha, nonTerminal);
}

int main() {
    char nonTerminal, alpha[10], beta[10];
    
    printf("Enter non-terminal: ");
    scanf(" %c", &nonTerminal);
    
    printf("Enter left-recursive production (A -> Aa | ß):\n");
    printf("Enter a: ");
    scanf("%s", alpha);
    
    printf("Enter ß: ");
    scanf("%s", beta);
    
    eliminateLeftRecursion(nonTerminal, alpha, beta);
    
    return 0;
}

