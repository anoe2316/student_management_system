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
        scanf("%d", &a);
        while (getchar() != '\n');
        if(a == 5) break;
        if(a == 1) 
        {
            student = addAction(student, &count); //add new student and return student pointer
            
            printStudent(&student[count-1]); //print recently add student info
            saveNew("student.txt", student,&count);
        }else if(a == 2)
        {
            showAction(student,&count); //show all students
            
        }else if(a == 3)
        {
            searchAction(student,&count); //search student by student number
        }else if(a == 4)
        {
            deleteAction(student,&count); //delete student by student number
            saveDelete("student.txt", student, &count);
        }
        
    }
    
    
    
    return 0;
}