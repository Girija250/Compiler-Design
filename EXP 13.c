#include <stdio.h>

int main() {
    char ch;
    int characters = 0, words = 0, lines = 0;
    char lastChar = ' ';

    printf("Enter text (Press Ctrl + D to stop input in Linux/Mac or Ctrl + Z in Windows):\n");

    // Read input character by character until EOF
    while ((ch = getchar()) != EOF) {
        characters++; // Count characters

        if (ch == '\n')
            lines++; // Count lines

        // Count words when a space, newline, or tab follows a valid character
        if ((ch == ' ' || ch == '\n' || ch == '\t') && (lastChar != ' ' && lastChar != '\n' && lastChar != '\t')) {
            words++;
        }

        lastChar = ch; // Update last character
    }

    // If the last character is not a space or newline, count the last word
    if (lastChar != ' ' && lastChar != '\n' && lastChar != '\t')
        words++;

    // Display results
    printf("\nLexical Analysis:\n");
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}

