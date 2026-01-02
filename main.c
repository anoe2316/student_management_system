#include <stdio.h>
#include "student.h"

int main()
{
    STUDENT* student = NULL;
    student = readFile("student.txt", &stdno, &count);   //read file and return number of old students
    // for(int i = 0;i < count;i++)
    // {
    //     printf("Name : %s\n", student[i].name);
    //     printf("Student Number : %d\n", student[i].id);
    //     printf("GPA : %.1f\n", student[i].gpa);
    //     printf("\n------------------------\n\n");
    // }
    
    int a;
    while(1)
    {
        printAction();
        scanf("%d", &a);
        while (getchar() != '\n');
        if(a == 5) break;
        if(a == 1) 
        {
            student = addAction(student, &count);
            
            printStudent(&student[count-1]);
        }else if(a == 2)
        {
            showAction(student,&count);
            
        }else if(a == 3)
        {
            searchAction(student,&count);
        }else if(a == 4)
        {
            deleteAction(student,&count);
        }
        
    }
    
    
    
    return 0;
}