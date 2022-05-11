//  Kashish Ahuja
//  Program for selection sort

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void main()
{
    int n, *arr;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    arr=(int *)malloc(sizeof(int));
    printf("Enter elements of array: ");
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);

    //  sorting
    for(int i=0; i<n-1; i++)
    {
        int min_idx=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        int temp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;
    }

    printf("\nArray elements after sorting: ");
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);

    getch();
}