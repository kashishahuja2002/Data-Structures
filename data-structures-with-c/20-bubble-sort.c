//  Kashish Ahuja
//  Program for bubble sort

#include<stdio.h>
#include<conio.h>

void main()
{
    int arr[15], i, j, n, temp;

    printf("Enter number of elements of array: ");
    scanf("%d",&n);

    printf("Enter elements of array: ");
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]); 

    //  sorting
    for(i=1; i<n; i++)
    {
        for(j=0; j<(n-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Array elements after sorting: ");
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);

    getch();
} 