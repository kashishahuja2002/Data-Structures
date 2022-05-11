//  Kashish Ahuja
//  Program for using typedef function

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Student
{
    int rollno;
    char name[20];
};

typedef struct Student node;

void main()
{
    node *s;
    s = (node *)malloc(sizeof(node));
    printf("Enter student's roll number: ");
    scanf("%d", &s->rollno);
    fflush(stdin);
    printf("Enter student's name: ");
    gets(s->name);
    printf("\nRoll no.: %d",s->rollno);
    printf("\nName: %s", s->name);
    free(s);
    getch();
}
