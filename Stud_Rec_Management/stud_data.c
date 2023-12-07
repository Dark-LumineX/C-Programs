#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

struct node
{
    int roll, mark;
    char name[20], course[10];
    struct node *pre, *next;
};
typedef struct node data;
//building new kind of variable and defining datatype

data *f, *p, *c, *t; 
//declaring variables

void gotoxy(int x,int y)
{
    COORD cor;
    cor.X=x;
    cor.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cor);
}
//Declaring gotoxy as it is a part of turbo c++ but not standard library

void insert()
{
    system("cls");
    c=(struct node *)malloc(sizeof(struct node));
    printf("Enter Name of Student\n");
    scanf("%s",&c->name);
    printf("Enter Roll Number of Student\n");
    scanf("%d",&c->roll);
    printf("Enter Course of Student\n");
    scanf("%s",&c->course);
    printf("Enter Total Marks of the Student\n");
    scanf("%d",&c->mark);
    c->next=NULL;
    if (f==NULL)
    {
        f=c;
    }
    else
    {
        c->pre=p;
        p->next=c;
    }
    p=c;
}
//function to insert student data

void show()
{
    system("cls");
    t=f;
    printf("Index                 Name     Course  Marks\n\n");
    while(t!=NULL)
    {
        printf("%5d %20s %10s  %5d\n",t->roll,t->name,t->course,t->mark);
        t=t->next;
    }
}
//function to show all data

void sname(char nam[20])
{
    int i=0,j;
    t=f;
    printf("Index                 Name     Course  Marks\n\n");
    while(t!=NULL)
    {
        j=strcmp(nam,t->name);
        if(j==0)
        {
            printf("%5d %20s %10s  %5d\n",t->roll,t->name,t->course,t->mark);
            i++;
        }
        t=t->next;
    }
    if(i==0)
    {
        printf("\n\nNo data found.");
    }
    else
    {
        printf("\n\n%d results found",i);
    }
}
//function to search names of the students

void scourse(char nam[10])
{
    int i=0,j;
    t=f;
    printf("Index                 Name     Course  Marks\n\n");
    while(t!=NULL)
    {
        j=strcmp(nam,t->course);
        if(j==0)
        {
            printf("%5d %20s %10s  %5d\n",t->roll,t->name,t->course,t->mark);
            i++;
        }
        t=t->next;
    }
    if(i==0)
    {
        printf("\n\nNo data found.");
    }
    else
    {
        printf("\n\n%d results found",i);
    }
}
//function to search courses of the students

void search()
{
    int a; char nam[20],cou[10];
    system("cls");
    printf("Press\n  1 to search by name\n  2 to search by course\n");
    printf("Enter your choice\n");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        printf("Enter name of the student:");
        scanf("%s",nam);
        sname(nam);
        printf("\nPress any key to exit");
        getch();
        break;
    
    case 2:
        printf("Enter the course:");
        scanf("%s",cou);
        scourse(cou);
        printf("\nPress any key to exit");
        getch();
        break;

    default:
        break;    
    }
}
//function for searching

void delete(int num)
{
    int i=0;
    data *m,*n;
    t=f;
    while(t!=NULL)
    {
        if(num==(t->roll))
        {
            printf("Data found\n");
            printf("Index                 Name     Course  Marks\n\n");
            printf("%5d %20s %10s  %5d\n",t->roll,t->name,t->course,t->mark);
            m=t->pre;
            n=t->next;
            m->next=n;
            n->pre=m;
            free(t);
            i++;
            break;
        }
        t=t->next;
    }
    if(i==0)
    {
        printf("\n\nNo data found to be deleted.");
    }
    else
    {
        printf("\n\nData deleted successfully.");
    }
}
//function to delete student data by roll no. as it is a unique no.

void main()
{
    int a,n;
    while(1)
    {
        system("cls");
        gotoxy(20,4); printf("welcome to Student Record Management System");
        gotoxy(15,6); printf("Press");
        gotoxy(15,7); printf("1 to create a new Record");
        gotoxy(15,8); printf("2 to delete a student record");
        gotoxy(15,9); printf("3 to search a student record");
        gotoxy(15,10); printf("4 to view all students record");
        gotoxy(15,11); printf("5 to exit");
        printf("\n\nEnter your Choice\n");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            insert();
            printf("Student data updated");
            getch();
            break;

        case 2:
            system("cls");
            printf("Enter Roll Number of Student whose record is to be deleted\n");
            scanf("%d",&n);
            delete(n);
            getch();
            break;

        case 3:
            search();
            break;
        
        case 4:
            show();
            getch();
            break;
        case 5:
            exit(0);

        default:
            break;
        }
    }
}
