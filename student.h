#ifndef STUDENT_H
#define STUDENT_H

#define maxname 10
typedef struct
{
    char name[maxname];
    int id;
    float gpa;
}STUDENT;
STUDENT student[100];
extern int count;
extern int stdno;
void printAction(void);
STUDENT* addAction(void);
void printStudent(STUDENT**student);
void showAction(STUDENT *student[],int *count);
void deleteAction(STUDENT *student[],int *count);
void searchAction(STUDENT *student[],int *count);

#endif