//  Kashish Ahuja
//  Program for using typedef

#include<iostream>
using namespace std;

struct Student
{
    int rollno;
    char name[20];
};

typedef struct Student node;

int main()
{
    node *s;
    s = new node;
    cout<<"Enter student's roll number: ";
    cin>>s->rollno;
    cout<<"Enter student's name: ";
    cin.get();
    cin.get(s->name,20);
    cout<<"\nRoll no.: "<<s->rollno;
    cout<<"\nName: "<< s->name;
    delete(s);
    return 0;
}
