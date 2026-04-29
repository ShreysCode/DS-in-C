/* =========================================================
2. Delete an element from array SIZE 10 + display function
========================================================= */
#include <stdio.h>

void display(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}

int main()
{
    int arr[10], n, pos, i;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Original Array:\n");
    display(arr,n);

    printf("\nEnter position to delete: ");
    scanf("%d",&pos);

    for(i=pos-1;i<n-1;i++)
        arr[i]=arr[i+1];

    n--;

    printf("Array after deletion:\n");
    display(arr,n);

    return 0;
}