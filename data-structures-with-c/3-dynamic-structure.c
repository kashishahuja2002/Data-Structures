//  Kashish Ahuja
//  Program for dynamic memory allocation in structure using malloc and free

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Student
{
    int rollno;
    char name[20];
};

void main()
{
    struct Student *s;
    s = (struct Student *)malloc(sizeof(struct Student));
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
