//  Kashish Ahuja
//  Applications of stack
//  Program for recursion (stack of calling function)

#include<iostream>
using namespace std;

int factorial(int n);

int main()
{
    int num, fact;
    cout<<"\nEnter a number: ";
    cin>>num;
    fact=factorial(num);
    cout<<"\nFactorial of "<<num<<" is "<<fact<<"\n";
    return 0;
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