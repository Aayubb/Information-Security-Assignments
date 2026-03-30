//Program implementing vigenere cipher

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void encipher();
void decipher();

int main() {
    int choice;

    while (1) {
        printf("\n 1. Encrypt text");
        printf("\t 2. Decrypt text");
        printf("\t 3. Exit");
        printf("\n\n Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 3) {
            printf("\nPress Enter to exit...");
            getchar();
            exit(0);
        }
        else if (choice == 1) {
            encipher();
        }
        else if (choice == 2) {
            decipher();
        }
        else {
            printf("Please enter a valid option.\n");
            printf("\nPress Enter to continue...");
            getchar();
        }
    }

    return 0;
}

// Encryption
void encipher() {
    unsigned int i, j;
    char input[50], key[50];

    printf("\nEnter plaintext (no spaces): ");
    scanf("%s", input);

    printf("Enter key value (no spaces): ");
    scanf("%s", key);

    printf("Resultant ciphertext: ");

    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (j >= strlen(key))
            j = 0;

        char c = ((toupper(input[i]) - 65 + (toupper(key[j]) - 65)) % 26) + 65;
        printf("%c", c);
    }

    printf("\n");
}

// Decryption
void decipher() {
    int i, j, value;
    char input[50], key[50];

    printf("\nEnter ciphertext (no spaces): ");
    scanf("%s", input);

    printf("Enter key value (no spaces): ");
    scanf("%s", key);

    printf("Resultant Plaintext: ");

    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (j >= strlen(key))
            j = 0;

        value = (toupper(input[i]) - toupper(key[j]) + 26) % 26;
        printf("%c", value + 65);
    }

    printf("\n");
}