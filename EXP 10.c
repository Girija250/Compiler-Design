#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int index = 0;

// Function declarations
void E();
void E_prime();
void T();
void T_prime();
void F();

void error() {
    printf("Error in parsing!\n");
    exit(0);
}

void match(char expected) {
    if (input[index] == expected) 
        index++;
    else 
        error();
}

void E() {
    T();
    E_prime();
}

void E_prime() {
    if (input[index] == '+') {
        match('+');
        T();
        E_prime();
    }
}

void T() {
    F();
    T_prime();
}

void T_prime() {
    if (input[index] == '*') {
        match('*');
        F();
        T_prime();
    }
}

void F() {
    if (input[index] == '(') {
        match('(');
        E();
        match(')');
    } else if (isalnum(input[index])) {
        match(input[index]); // Matching id (single character variables)
    } else {
        error();
    }
}

int main() {
    printf("Enter an expression: ");
    scanf("%s", input);
    
    E();

    if (input[index] == '\0')
        printf("Parsing successful!\n");
    else
        printf("Parsing failed!\n");

    return 0;
}

