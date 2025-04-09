#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
 
int isValidIdentifier(char *str) { 
    if (!isalpha(str[0]) && str[0] != '_') return 0; 
    for (int i = 1; str[i] != '\0'; i++) { 
        if (!isalnum(str[i]) && str[i] != '_') return 0; 
    } 
    return 1; 
} 
 
void checkIdentifier(char *identifier) { 
    if (isValidIdentifier(identifier)) { 
        printf("\"%s\" is a valid identifier.\n", identifier); 
    } else { 
        printf("\"%s\" is not a valid identifier.\n", identifier); 
    } 
} 
 
int main() { 
char id1[] = "var_name"; 
char id2[] = "2ndVariable"; 
checkIdentifier(id1); 
checkIdentifier(id2); 
return 0; 
}
