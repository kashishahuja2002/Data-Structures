//  Kashish Ahuja
//  Program for dynamic memory allocation in 1D and 2D array

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void main()
{
    int *arr_1, **arr_2;
    int n, r, c;
    
    printf("Enter number of elements in 1D array: ");
    scanf("%d",&n);
    arr_1 = (int *)malloc(n*sizeof(int));
    printf("Enter array elements: ");
    for(int i=0; i<n; i++)
        scanf("%d",arr_1+i);
    printf("1D array: ");
    for(int i=0; i<n; i++)
        printf("%d ",arr_1[i]);
    free(arr_1);

    printf("\nEnter number of rows and columns in 2D array: ");
    scanf("%d %d",&r, &c);
    arr_2 = (int **)malloc(r*sizeof(int *));
    for(int i=0; i<r; i++)
        arr_2[i] = (int *)malloc(c*sizeof(int));
    printf("Enter array elements: ");
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            int num; 
            scanf("%d",&num);
            arr_2[i][j]=num;
        }
    }
    printf("2D array: ");
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            printf("%d ",arr_2[i][j]);
    free(arr_2);

    getch();
}