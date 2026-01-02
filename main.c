#include <stdio.h>
#include "student.h"

int main()
{
    STUDENT* student = NULL;
    student = readFile("student.txt", &stdno, &count);   //read file and return student pointer

    int a;
    while(1)
    {
        printAction();
        printf("Enter your action : ");
        scanf("%d", &a);
        while (getchar() != '\n');
        switch(a)
        {
            case 1: 
                student = addAction(student, &count); //add new student and return student pointer
                printStudent(&student[count-1]); //print recently add student info
                saveNew("student.txt", student,&count);
                break;
            case 2:
                showAction(student,&count); //show all students
                break;
            case 3:
                searchAction(student,&count); //search student by student number
                break;
            case 4:
                deleteAction(student,&count); //delete student by student number
                saveDelete("student.txt", student, &count);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid Input : Try Again!\n\n");
            
                
        }
        
    }
    
    
    
    return 0;
}