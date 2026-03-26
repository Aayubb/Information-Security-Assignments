#include <stdio.h>

// Fast modular exponentiation
long long int power(int a, int b, int mod) {
    long long int t;

    if (b == 0)
        return 1;

    if (b == 1)
        return a % mod;

    t = power(a, b / 2, mod);

    if (b % 2 == 0)
        return (t * t) % mod;
    else
        return ((t * t) % mod * a) % mod;
}

// Check primitive root
int isP_Root(int g, int n) {
    int value[1000];   // fixed size instead of VLA (safer for beginners)
    int i, result;

    for (i = 0; i < n; i++) {
        value[i] = 0;
    }

    for (i = 1; i < n; i++) {
        result = power(g, i, n);

        if (value[result] == 1) {
            return 0;  // not primitive root
        }

        value[result] = 1;
    }

    return 1;
}

int main() {
    int n, g, x, y;
    long long int a, b;

    printf("Enter the value of n and g: ");
    scanf("%d %d", &n, &g);

    if (!isP_Root(g, n)) {
        printf("%d is NOT a primitive root of %d\n", g, n);
        return 0;
    }

    printf("%d is a primitive root of %d\n", g, n);

    printf("Enter the value of x for the first person: ");
    scanf("%d", &x);

    a = power(g, x, n);

    printf("Enter the value of y for the second person: ");
    scanf("%d", &y);

    b = power(g, y, n);

    printf("Public key of first person: %lld\n", a);
    printf("Public key of second person: %lld\n", b);

    printf("Key for the first person is: %lld\n", power(b, x, n));
    printf("Key for the second person is: %lld\n", power(a, y, n));

    return 0;
}