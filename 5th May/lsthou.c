#include <stdio.h>
void main()
{
    int size = 12 , arr[size], i, search, flag = 0;
    printf("Enter the %d elements of the array :", size);
    for (i = 0 ; i < 12 ; i++){
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to search : ");
    scanf("%d", &search);
    for (i = 0 ; i < 12 ; i++){
        if(arr[i] == search){
            printf("\nElement %d found at index %d.\n", search, i);
            flag++;
        }
    }
    if(flag = 0){
        printf("\n Element %d is not found.\n", search);
    }
}

