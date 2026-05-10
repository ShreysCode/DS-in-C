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
    int x;
    
    printf("Enter a positive number: ");
    scanf("%d", &x);

    int smaller = x - 1;
    int greater = x + 1;

    while (smaller > 1) {
        if (isPrime(smaller)) {
            break;
        }
        smaller--;
    }

    while (1) {
        if (isPrime(greater)) {
            break;
        }
        greater++;
    }

    if (smaller > 1)
        printf("\nA prime number less than %d is %d.\n", x, smaller);
    else
        printf("\nNo prime number exists less than %d.\n", x);

    printf("A prime number greater than %d is %d.\n", x, greater);

    return 0;
}