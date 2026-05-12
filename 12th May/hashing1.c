// Write a C program to store the following elements in an array by hashing.
//  Consider hash function as x%10 
// 36, 5, 48, 91, 50, 32, 77, 44, 63, 29
//  Display the contents of the array after storing the elements. 

#include <stdio.h>

#define SIZE 10

int main() {
    int hashTable[SIZE];
    int n;

    // Initialize hash table
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int data[n];

    // Input elements
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // Insert elements using Linear Probing
    for(int i = 0; i < n; i++) {

        int key = data[i];
        int index = key % SIZE;

        // Handle collision using linear probing
        while(hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }

        hashTable[index] = key;
    }

    // Display hash table
    printf("\nHash Table Contents:\n");

    for(int i = 0; i < SIZE; i++) {

        if(hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : EMPTY\n", i);
    }

    return 0;
}
