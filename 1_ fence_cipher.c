// Program that enypts and decrypts a message usign the fence cipher method.

#include <stdio.h>
#include <string.h>

int main() {
    int i, j, l, mid;
    char a[100], c[100], d[100];

    printf("\n \t Railfence Technique");
    printf("\n\n Enter the input string: ");
    fgets(a, sizeof(a), stdin);

    l = strlen(a);

    // Remove newline
    if (a[l - 1] == '\n') {
        a[l - 1] = '\0';
        l--;
    }

    // Ciphering (Rail Fence - 2 rows)
    j = 0;
    for (i = 0; i < l; i++) {
        if (i % 2 == 0) {
            c[j++] = a[i];
        }
    }

    for (i = 0; i < l; i++) {
        if (i % 2 == 1) {
            c[j++] = a[i];
        }
    }

    c[j] = '\0';

    printf("\nCipher text after applying railfence: %s\n", c);

    // Deciphering
    if (l % 2 == 0) {
        mid = l / 2;
    } else {
        mid = (l / 2) + 1;
    }

    int evenIndex = 0, oddIndex = mid;

    for (i = 0; i < l; i++) {
        if (i % 2 == 0) {
            d[i] = c[evenIndex++];
        } else {
            d[i] = c[oddIndex++];
        }
    }

    d[l] = '\0';

    printf("\nDecrypted text: %s\n", d);

    return 0;
}