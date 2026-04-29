/* =========================================================
1. Insert an element at a specific position in array SIZE 10
========================================================= */

#include <stdio.h>

int main()
{
    int arr[10], n, i, pos, val;

    printf("Enter number of elements (max 9): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter position to insert (1 to %d): ", n+1);
    scanf("%d",&pos);

    printf("Enter value: ");
    scanf("%d",&val);

    for(i=n;i>=pos;i--)
        arr[i]=arr[i-1];

    arr[pos-1]=val;
    n++;

    printf("Array after insertion:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}