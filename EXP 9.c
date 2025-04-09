#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Simple Grammar: S -> aSb | ab
int checkGrammar(char str[], int left, int right) {
    if (left > right) return 0; // Invalid case

    if (left == right - 1 && str[left] == 'a' && str[right] == 'b') 
        return 1; // Matches "ab"

    if (str[left] == 'a' && str[right] == 'b') 
        return checkGrammar(str, left + 1, right - 1); // Matches "aSb"

    return 0; // Not matching the grammar
}

int main() {
    char str[100];

    printf("Enter the input string: ");
    scanf("%s", str);

    int len = strlen(str);
    
    if (checkGrammar(str, 0, len - 1))
        printf("The string satisfies the grammar.\n");
    else
        printf("The string does not satisfy the grammar.\n");

    return 0;
}

