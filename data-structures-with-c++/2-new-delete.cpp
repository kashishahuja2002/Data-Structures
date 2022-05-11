//  Kashish Ahuja
//  Program for dynamic memory allocation (done with pointers) using new and delete

#include<iostream>
using namespace std;

int main()
{
    int *p,*q, *r;
    p = new int;
    q = new int;
    cout<<"Enter two integers: ";
    cin>>*p>>*q;           
    r = new int;
    *r = *p + *q;
    cout<<"Sum is: "<< *r;
    delete(p);
    delete(q);
    delete(r);
    return 0;
}