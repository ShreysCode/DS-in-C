#include <stdio.h>

int isPrime(int num) {
    if (num <= 1)
        return 0;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int a, b, c, d, e;
    int max;

    printf("Enter five numbers:\n");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    max = (max > d) ? max : d;
    max = (max > e) ? max : e;

    printf("\n Largest number = %d\n", max);

    if (isPrime(max))
        printf("The largest number is PRIME.\n");
    else
        printf("The largest number is NOT PRIME.\n");

    return 0;
}