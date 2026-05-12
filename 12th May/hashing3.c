// Write a C program to store the following elements in an array by hashing. Consider hash function as x%10. 
// Use quadratic probing in case of collision.
//  26, 99, 59, 91, 50, 32, 72, 44, 66, 29 
// Display the contents of the array after storing the elements. 

#include <stdio.h>

#define SIZE 10

int main() {
    int hashTable[SIZE];
    int n;

    // Initialize hash table with -1
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

    // Insert using Quadratic Probing
    for(int i = 0; i < n; i++) {
        int key = data[i];
        int index = key % SIZE;

        int j = 0;
        int newIndex;

        while(j < SIZE) {
            newIndex = (index + j * j) % SIZE;

            if(hashTable[newIndex] == -1) {
                hashTable[newIndex] = key;
                break;
            }

            j++;
        }

        // Table Full Condition
        if(j == SIZE) {
            printf("Hash table is full. Cannot insert %d\n", key);
        }
    }

    // Display Hash Table
    printf("\nHash Table Contents:\n");

    for(int i = 0; i < SIZE; i++) {
        if(hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : EMPTY\n", i);
    }

    return 0;
}