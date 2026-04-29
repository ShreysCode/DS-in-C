/* =========================================================
4. Reverse an array of SIZE 10
========================================================= */
#include <stdio.h>

int main()
{
    int arr[10], i, temp;

    printf("Enter 10 elements:\n");
    for(i=0;i<10;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<5;i++)
    {
        temp=arr[i];
        arr[i]=arr[9-i];
        arr[9-i]=temp;
    }

    printf("Reversed Array:\n");
    for(i=0;i<10;i++)
        printf("%d ",arr[i]);

    return 0;
}