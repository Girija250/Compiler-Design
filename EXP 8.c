#include <stdio.h>
#include <string.h>

#define SIZE 10

struct Symbol {
    char name[20];
    char type[10];
} table[SIZE];

int count = 0;

void insert() {
    if (count < SIZE) {
        printf("Enter symbol name: ");
        scanf("%s", table[count].name);
        printf("Enter type: ");
        scanf("%s", table[count].type);
        count++;
        printf("Symbol inserted successfully!\n");
    } else {
        printf("Symbol table full!\n");
    }
}

void search() {
    char name[20];
    printf("Enter symbol name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Symbol found: %s, Type: %s\n", table[i].name, table[i].type);
            return;
        }
    }
    printf("Symbol not found!\n");
}

void display() {
    printf("\nSymbol Table:\n");
    printf("Name\tType\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", table[i].name, table[i].type);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

