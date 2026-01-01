#include <stdio.h>
#include "student.h"




int main()
{
    STUDENT* student[100];
    
    int a;
    while(1)
    {
        printAction();
        printf("Enter your action : ");
        scanf("%d", &a);
        while (getchar() != '\n');
        if(a == 5) break;
        if(a == 1) 
        {
            student[++count] = addAction();
            
            printStudent(&student[count]);
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