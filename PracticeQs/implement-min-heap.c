#include <stdio.h>

#define SIZE 100

int heap[SIZE];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {

    if(heapSize >= SIZE) {
        printf("Heap Overflow\n");
        return;
    }

    int i = heapSize;
    heap[heapSize++] = value;

    // Heapify Up
    while(i != 0 && heap[(i - 1) / 2] > heap[i]) {

        swap(&heap[(i - 1) / 2], &heap[i]);

        i = (i - 1) / 2;
    }
}

void heapify(int i) {

    int smallest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < heapSize && heap[left] < heap[smallest])
        smallest = left;

    if(right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {

        swap(&heap[i], &heap[smallest]);

        heapify(smallest);
    }
}

int deleteMin() {

    if(heapSize <= 0)
        return -1;

    if(heapSize == 1)
        return heap[--heapSize];

    int root = heap[0];

    heap[0] = heap[--heapSize];

    heapify(0);

    return root;
}

void display() {

    for(int i = 0; i < heapSize; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main() {

    insert(20);
    insert(10);
    insert(5);
    insert(30);
    insert(2);

    printf("Heap:\n");
    display();

    printf("Deleted Min: %d\n", deleteMin());

    printf("Heap After Deletion:\n");
    display();

    return 0;
}