//  Kashish Ahuja
//  Program for dynamic memory allocation (done with pointers) using malloc and free 

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void main()
{
    int *p,*q, *r;
    p = (int *)malloc(sizeof(int));
    q = (int *)malloc(2);
    printf("Enter two integers: ");
    scanf("%d %d", p, q);           //  & is not used in case of pointers
    r = (int *)malloc(sizeof(p));
    *r = *p + *q;
    printf("Sum is: %d", *r);
    free(p);
    free(q);
    free(r);
    getch();
}