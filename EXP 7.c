#include <stdio.h>
#include <string.h>

void eliminateLeftFactoring(char nonTerminal, char common[], char alpha[], char beta[]) {
    printf("Grammar after eliminating left factoring:\n");
    printf("%c -> %s%c'\n", nonTerminal, common, nonTerminal);
    printf("%c' -> %s | %s | e\n", nonTerminal, alpha, beta);
}

int main() {
    char nonTerminal, common[10], alpha[10], beta[10];

    printf("Enter non-terminal: ");
    scanf(" %c", &nonTerminal);

    printf("Enter common prefix: ");
    scanf("%s", common);

    printf("Enter a (remaining part of first production): ");
    scanf("%s", alpha);

    printf("Enter ß (remaining part of second production): ");
    scanf("%s", beta);

    eliminateLeftFactoring(nonTerminal, common, alpha, beta);

    return 0;
}

