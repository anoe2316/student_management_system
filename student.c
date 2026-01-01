#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "student.h"

int count = 0;
int stdno = 1000;
void printAction(void)
{
    printf("1.Add Student\n");
    printf("2.Show All Student\n");
    printf("3.Search Student\n");
    printf("4.Delete Student\n");
    printf("5.Exit\n");
}
STUDENT* addAction(void)
{
    STUDENT* new = (STUDENT*)malloc(sizeof(STUDENT));
    printf("Enter the name of Student : ");
    fgets(new->name, sizeof(new->name), stdin);
    new->name[strcspn(new->name,"\n")] = '\0';
    for(int i = 0;new->name[i];i++)
    {
        new->name[i] = toupper((unsigned char)new->name[i]);
    }
    new->id = ++stdno;
    
    printf("Enter the GPA : ");
    scanf("%f", &new->gpa);
    return new;    
    
}
void printStudent(STUDENT**student)
{
    printf("\nStudent Registered : \n\n");
    printf("Name : %s\n", (*student)->name);
    printf("Student Number : %d\n", (*student)->id);
    printf("GPA : %.1f\n", (*student)->gpa);
    printf("\n------------------------\n\n");
}
void showAction(STUDENT *student[],int *count)
{
    printf("\nNumber of Student : %d\n\n", *count);
    for(int i=1;i<= *count;i++)
    {
    printf("Name : %s\n", student[i]->name);
    printf("Student Number : %d\n", student[i]->id);
    printf("GPA : %.1f\n", student[i]->gpa);
    printf("\n------------------------\n\n");
    }
}
void searchAction(STUDENT *student[],int *count)
{
    int tar;
    printf("Enter the student number :");
    scanf("%d", &tar);
    for(int i = 1;i <= *count;i++)
    {
        if(tar == student[i]->id)
        {
            printf("\nStudent have found : \n\n");
            printf("Name : %s\n", student[i]->name);
            printf("Student Number : %d\n", student[i]->id);
            printf("GPA : %.1f\n", student[i]->gpa);
            printf("\n------------------------\n\n");
            return;
        }
    }
    printf("\nStudent have not found!\n\n");
    printf("\n------------------------\n\n");
}

void deleteAction(STUDENT *student[],int *count)
{
    int tar;
    printf("Enter the student number :");
    scanf("%d", &tar);
    for(int i = 1;i <= *count;i++)
    {
        if(tar == student[i]->id)
        {
            free(student[i]);
            for(int j = i;j <= (*count);j++)
            {
                student[j] = student[j+1];
            }
            student[*count] = NULL;
            (*count)--;
            printf("\nSuccessfully Delete!\n\n");
            printf("\n------------------------\n\n");
        }
    }
    
    
}