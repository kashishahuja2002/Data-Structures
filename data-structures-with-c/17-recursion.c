//  Kashish Ahuja
//  Applications of stack
//  Program for direct recursion (stack of calling function)

#include<stdio.h>
#include<conio.h>

int factorial(int n);

void main()
{
    int num, fact;
    printf("\nEnter a number: ");
    scanf("%d",&num);
    fact=factorial(num);
    printf("\nFactorial of %d is %d\n",num,fact);
    getch();
}

int factorial(int n)
{
    int f;
    if(n==1)
        return 1;
    else
    {
        f=n*factorial(n-1);
        return f;
    }
}