#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define maxname 20
#define MAXSTUDENT 100
typedef struct
{
    char name[maxname];
    int id;
    float gpa;
}STUDENT;
int stdno = 1000;
int count = 0;
STUDENT student[100];

STUDENT* addstudent()
{
    STUDENT* student = (STUDENT*)malloc(sizeof(STUDENT));
            printf("Enter the name:");
            fgets(student->name, sizeof(student->name), stdin);
            student->name[strcspn(student->name,"\n")] = '\0';
            student->id = ++stdno;
            printf("Enter the GPA : ");
            scanf("%f", &student->gpa);
            printf("\nStudent Registered : \n\n");
            printf("Name : %s\n", student->name);
            printf("Student Number : %d\n", student->id);
            printf("GPA : %.1f\n", student->gpa);
            printf("\n------------------------\n\n");
            
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
void readFile(const char*filename)
{
    char line[100];
    char *token;
    FILE*fp = fopen(filename,"r");
    
    while (fgets(line, sizeof(line), fp)) 
    {
        count++;        
    }
    fclose(fp);

    fp = fopen(filename, "r");
    for(int i = 1;i <= count;i++)
    {

        fgets(line,sizeof(line),fp);
        line[strcspn(line,"\n")] = '\0';

        token = strtok(line,",");
        strcpy(student[i].name, token);

        token = strtok(NULL,",");
        student[i].id = atoi(token);

        token = strtok(NULL,",");
        student[i].gpa = atof(token);

        printf("Name : %s\n", student[i].name);
        printf("Student Name : %d\n", student[i].id);
        printf("GPA : %.1f", student[i].gpa);
    }    

}

int main(){

    int a;
    
    
    // readFile("test.txt");
//    while(1)       
//     {
//         printAction();
//         printf("Enter your action : ");
//         scanf("%d", &a);
//         while (getchar() != '\n');
//         if(a == 2) break;
//         if(a == 1) 
//         {
//               student[++count] = addstudent();     
//         }
    

    
//     }
    return 0;
}
