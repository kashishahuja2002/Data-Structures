//  Kashish Ahuja
//  Program for linear search

#include<stdio.h>
#include<conio.h>

void main()
{
    int arr[15], i, n, key, search=0;

    printf("Enter number of elements of array: ");
    scanf("%d",&n);

    printf("Enter elements of array: ");
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]); 

    printf("Enter the key element to be searched: ");
    scanf("%d",&key);

    //  searching
    for(i=0; i<n; i++)
    {
        if(key==arr[i])
        {
            printf("\nKey element %d found at location %d",key,i);
            search=1;
        }
    }
    if(search==0)
    {
        printf("\nKey element %d not found in array.",key);
    }

    getch();
} 
