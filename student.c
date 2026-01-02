#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "student.h"

//number of students
int stdno = 0;// counting student number
int count = 0;

STUDENT* readFile(const char *filename, int *stdno, int *count)
{
    char line[100];
    char* token;
    *count = 0;
    FILE *fp = fopen(filename, "r");
    
    while (fgets(line, sizeof(line), fp)) 
    {
        (*count)++;   //number of line or number of students     
    }
    fclose(fp);

    fp = fopen(filename, "r");
    STUDENT*student = malloc(sizeof(STUDENT) * (*count)); //creating new student
    
    for(int i = 0; i < *count;i++)       //read and add old students from file
    {
        fgets(line,sizeof(line),fp);                
        line[strcspn(line,"\n")] = '\0';

        token = strtok(line,",");
        strcpy(student[i].name, token);

        token = strtok(NULL,",");
        student[i].id = atoi(token);

        token = strtok(NULL,",");
        student[i].gpa = atof(token);
        
    }
    *stdno = student[*count - 1].id; //last student id;
    return student;
    

}

void printAction(void)
{
    printf("1.Add Student\n");
    printf("2.Show All Student\n");
    printf("3.Search Student\n");
    printf("4.Delete Student\n");
    printf("5.Exit\n");
}

STUDENT* addAction(STUDENT*student, int *count)
{
    STUDENT *new = realloc(student, sizeof(STUDENT) * ((*count) + 1)); //adding new student
     
    student = new;
    STUDENT *s = &student[*count];

    printf("Enter the name of Student : ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name,"\n")] = '\0';
    for(int i = 0;s->name[i];i++)
    {
        s->name[i] = toupper((unsigned char)s->name[i]);
    }
    s->id = ++stdno;
    
    printf("Enter the GPA : ");
    scanf("%f", &s->gpa);
    (*count)++; 
    return student;    
    
}

void printStudent(const STUDENT *student)
{
    printf("\nStudent Registered : \n\n");
    printf("Name : %s\n", (student)->name);
    printf("Student Number : %d\n", (student)->id);
    printf("GPA : %.1f\n", (student)->gpa);
    printf("\n------------------------\n\n");
}

void showAction(STUDENT *student,int *count)
{
    printf("\nNumber of Student : %d\n\n", *count);
    for(int i = 0;i < *count;i++)
    {
    printf("Name : %s\n", student[i].name);
    printf("Student Number : %d\n", student[i].id);
    printf("GPA : %.1f\n", student[i].gpa);
    printf("\n------------------------\n\n");
    }
}

void searchAction(STUDENT *student,int *count)
{
    int tar;
    printf("Enter the student number :");
    scanf("%d", &tar);
    for(int i = 1;i <= *count;i++)
    {
        if(tar == student[i].id)
        {
            printf("\nStudent have found : \n\n");
            printf("Name : %s\n", student[i].name);
            printf("Student Number : %d\n", student[i].id);
            printf("GPA : %.1f\n", student[i].gpa);
            printf("\n------------------------\n\n");
            return;
        }
    }
    printf("\nStudent have not found!\n\n");
    printf("\n------------------------\n\n");
}

void deleteAction(STUDENT *student,int *count)
{
    int tar;
    printf("Enter the student number :");
    scanf("%d", &tar);
    for(int i = 0;i < *count;i++)
    {
        if(tar == student[i].id)
        {
            
            for(int j = i;j <= (*count - 1);j++)
            {
                student[j] = student[j+1];
            }
            
            (*count)--;
            printf("\nSuccessfully Delete!\n\n");
            printf("\n------------------------\n\n");
            return;
        }
    }
    printf("Student not found.\n");
    
    
}