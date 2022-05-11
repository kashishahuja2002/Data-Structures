//  Kashish Ahuja
//  Program for dynamic memory allocation in structure using new and delete

#include<iostream>
using namespace std;

struct Student
{
    int rollno;
    char name[20];
};

int main()
{
    struct Student *s;
    s = new struct Student;
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
