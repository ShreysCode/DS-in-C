#include <stdio.h>

// Binary search for descending sorted array
int binarySearchDesc(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            high = mid - 1;   // move LEFT (opposite of ascending)
        }
        else {
            low = mid + 1;    // move RIGHT
        }
    }

    return -1;
}

int main() {
    int size = 8;
    int arr[size];
    int key;

    printf("Enter %d elements in DESCENDING order:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearchDesc(arr, size, key);

    if (result != -1) {
        printf("Element found at index %d (position %d)\n", result, result + 1);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}