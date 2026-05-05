#include <stdio.h>

// Binary search function
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // avoids overflow

        if (arr[mid] == key) {
            return mid;  // element found
        } 
        else if (arr[mid] < key) {
            low = mid + 1;  // search right half
        } 
        else {
            high = mid - 1; // search left half
        }
    }

    return -1; // not found
}

int main() {
    int size = 10;
    int arr[size];
    int key;

    // Input sorted array
    printf("Enter %d elements in ascending order\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Input key
    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, size, key);

    if (result != -1) {
        printf("Element found at index %d (position %d)\n", result, result + 1);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}