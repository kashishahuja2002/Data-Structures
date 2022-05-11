//  Kashish Ahuja
//  Program for insertion sort

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
    for(int i=1; i<n; i++)
    {
        int temp=arr[i];
        int j=i-1;
        while((j>=0) && temp<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    printf("\nArray elements after sorting: ");
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);

    getch();
}