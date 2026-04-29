/* =========================================================
3. Find second largest and second smallest in array SIZE 10
========================================================= */
#include <stdio.h>

int main()
{
    int arr[10], i, j, temp;

    printf("Enter 10 elements:\n");
    for(i=0;i<10;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(arr[i] > arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    printf("Second Smallest = %d\n", arr[1]);
    printf("Second Largest = %d\n", arr[8]);

    return 0;
}