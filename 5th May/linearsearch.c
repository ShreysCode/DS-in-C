#include <stdio.h>

// Function for linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // return index if found
        }
    }
    return -1; // not found
}

int main() {
    int size = 12;
    int arr[size];
    int key;

    // Input array elements
    printf("Enter %d elements\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Input search key
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Call function
    int result = linearSearch(arr, size, key);

    // Output result
    if (result != -1) {
        printf("Element found at index %d (position %d)\n", result, result + 1);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}