#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Element {
    int atomicNumber;
    char symbol[5];
    char name[20];
    float atomicWeight;
    int group;
    int period;
    char block;
    char category[30];
};

// Convert string to lowercase for case-insensitive comparison
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to display element details
void displayElement(struct Element e) {
    printf("--------------------------------------------------\n");
    printf("Atomic Number : %d\n", e.atomicNumber);
    printf("Symbol        : %s\n", e.symbol);
    printf("Name          : %s\n", e.name);
    printf("Atomic Weight : %.4f\n", e.atomicWeight);
    printf("Group         : %d\n", e.group);
    printf("Period        : %d\n", e.period);
    printf("Block         : %c\n", e.block);
    printf("Category      : %s\n", e.category);
    printf("--------------------------------------------------\n");
}

// Search element by atomic number
void searchByNumber(struct Element elements[], int n, int num) {
    for (int i = 0; i < n; i++) {
        if (elements[i].atomicNumber == num) {
            displayElement(elements[i]);
            return;
        }
    }
    printf("Element with atomic number %d not found.\n", num);
}

// Search element by name or symbol
void searchByText(struct Element elements[], int n, char text[]) {
    char query[20];
    strcpy(query, text);
    toLowerCase(query);

    for (int i = 0; i < n; i++) {
        char name[20], symbol[5];
        strcpy(name, elements[i].name);
        strcpy(symbol, elements[i].symbol);
        toLowerCase(name);
        toLowerCase(symbol);

        if (strcmp(name, query) == 0 || strcmp(symbol, query) == 0) {
            displayElement(elements[i]);
            return;
        }
    }
    printf("Element '%s' not found.\n", text);
}

// Display all elements in short form
void listAll(struct Element elements[], int n) {
    printf("#   Symbol   Name\n");
    printf("-------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%2d   %-3s     %s\n", elements[i].atomicNumber, elements[i].symbol, elements[i].name);
    }
}

int main() {
    struct Element elements[20] = {
        {1, "H", "Hydrogen", 1.008, 1, 1, 's', "Nonmetal"},
        {2, "He", "Helium", 4.0026, 18, 1, 's', "Noble Gas"},
        {3, "Li", "Lithium", 6.94, 1, 2, 's', "Alkali Metal"},
        {4, "Be", "Beryllium", 9.0122, 2, 2, 's', "Alkaline Earth"},
        {5, "B", "Boron", 10.81, 13, 2, 'p', "Metalloid"},
        {6, "C", "Carbon", 12.011, 14, 2, 'p', "Nonmetal"},
        {7, "N", "Nitrogen", 14.007, 15, 2, 'p', "Nonmetal"},
        {8, "O", "Oxygen", 15.999, 16, 2, 'p', "Nonmetal"},
        {9, "F", "Fluorine", 18.998, 17, 2, 'p', "Halogen"},
        {10, "Ne", "Neon", 20.180, 18, 2, 'p', "Noble Gas"},
        {11, "Na", "Sodium", 22.990, 1, 3, 's', "Alkali Metal"},
        {12, "Mg", "Magnesium", 24.305, 2, 3, 's', "Alkaline Earth"},
        {13, "Al", "Aluminium", 26.982, 13, 3, 'p', "Post-Transition Metal"},
        {14, "Si", "Silicon", 28.085, 14, 3, 'p', "Metalloid"},
        {15, "P", "Phosphorus", 30.974, 15, 3, 'p', "Nonmetal"},
        {16, "S", "Sulfur", 32.06, 16, 3, 'p', "Nonmetal"},
        {17, "Cl", "Chlorine", 35.45, 17, 3, 'p', "Halogen"},
        {18, "Ar", "Argon", 39.948, 18, 3, 'p', "Noble Gas"},
        {19, "K", "Potassium", 39.098, 1, 4, 's', "Alkali Metal"},
        {20, "Ca", "Calcium", 40.078, 2, 4, 's', "Alkaline Earth"}
    };

    int choice, num;
    char text[20];

    while (1) {
        printf("\n===== Modern Periodic Table =====\n");
        printf("1. Search by Atomic Number\n");
        printf("2. Search by Name or Symbol\n");
        printf("3. List All Elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Atomic Number: ");
                scanf("%d", &num);
                searchByNumber(elements, 20, num);
                break;
            case 2:
                printf("Enter Element Name or Symbol: ");
                scanf("%s", text);
                searchByText(elements, 20, text);
                break;
            case 3:
                listAll(elements, 20);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
