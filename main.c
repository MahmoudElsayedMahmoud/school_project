#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    info Data;
    Stack s;
    int ID;
    CreateStack(&s);
    int choice, std_no, i;


    while (true)
    {

        printf("\n\t***\t***\t***\t***Welcome ***\t***\t***\t***");
        printf("\n\n\t\t\t What Do You Want To Do?");
        printf("\n\t\t\t 1. Add Student");
        printf("\n\t\t\t 2. Edit Student");
        printf("\n\t\t\t 3. Delete Student");
        printf("\n\t\t\t 4. View All Students");
        printf("\n\t\t\t 5. Students Rank");
        printf("\n\t\t\t 6. Update Scores");
        printf("\n\t\t\t 7. Clear DataBase");
        printf("\n\n\n\t\t\t I Want to: ");
        scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            printf("\t\t\tNumber of Students to Add: ");
            scanf("%d",&std_no);

        for (i=0;i<std_no;i++)
        {
            printf("\n\t\t\tStudent %d ID: ",i+1);
            Data.ID = s.Size+1;
            fflush(stdin);
            printf("\n\t\t\tID: %d ",Data.ID);
            printf("\n\t\t\tStudent Name: ");
            gets(Data.name);
            fflush(stdin);
            printf("\n\t\t\tStudent Birthday...");
            printf("\n\t\t\tDay: ");
            scanf("%d",&(Data.birthday.day));
            while (Data.birthday.day>31 || Data.birthday.day==0)
                {printf("\n\t\t\tPlease Enter the Correct Day: ");
                scanf("%d",&(Data.birthday.day));}

            printf("\n\t\t\tMonth: ");
            scanf("%d",&(Data.birthday.month));
            while (Data.birthday.month>12 || Data.birthday.month==0)
                {printf("\n\t\t\tPlease Enter the Correct Month: ");
                scanf("%d",&(Data.birthday.month));}
                printf("\n\t\t\tYear: ");
                scanf("%d",&(Data.birthday.year));
            while (Data.birthday.year<2000 || Data.birthday.year>2014)
                {printf("\n\t\t\tPlease Enter the Correct Year: ");
                scanf("%d",&(Data.birthday.year));}
            fflush(stdin);
            printf("\n\t\t\tStudent Phone: ");
            gets(Data.phone);
            fflush(stdin);

            printf("\n\t\t\tStudent Address: ");
            gets(Data.address);
            fflush(stdin);



            printf("\n\t\t\tStudent scores: ");
            printf("\n\t\t\t math score = ");
            scanf("%f",&Data.score.math);
            printf("\n\t\t\t english score =  ");
            scanf("%f",&Data.score.english);
            printf("\n\t\t\t cs score =  ");
            scanf("%f",&Data.score.cs);


            Add_Student(Data,&s);
        }
        break;

    case 2:
        printf("\t\t\tNumber of Students to Edit: ");
        scanf("%d",&std_no);
        printf("\t\t\tWhat do you want to Edit?");
        //printf("\n\t\t\t1. Score");
        printf("\n\t\t\t1. Phone");
        printf("\n\t\t\t2. Address");
        printf("\n\n\t\t\tMy Option is: ");
        scanf("%d",&choice);
        for (i=0;i<std_no;i++)
        {
            printf("\t\t\tStudent %d ID: ",i+1);
            scanf("%d",&ID);
            if (Search (ID,&s))
                Edit_Student (ID,choice,&s);
            else
            printf("ID is NOT Exist");
        }
        break;

    case 3:
        printf("\t\t\tNumber of Students to Delete: ");
        scanf("%d",&std_no);

        for (i=0;i<std_no;i++)
        {
            printf("\t\t\tStudent %d ID: ",i+1);
            scanf("%d",&ID);
            if (Search (ID,&s))
                Delete_Student (ID,&s);
            else
            printf("ID is NOT Exist");
        }
        break;

    case 4:
        printf("case 4 is select\n");
        Student_Sort(&s);
        Student_list(&s);

       break;
    case 5:
        Rank_Student(&s);
        break;
    case 6:
       printf("\t\t\t Number of Students to update: ");
        scanf("%d",&std_no);
        printf("\t\t\t What do you want to update?");
        printf("\n\t\t\t1. math Score");
        printf("\n\t\t\t2. english Score");
        printf("\n\t\t\t3. CS Score");
        printf("\n\n\t\t\tMy Option is: ");
        scanf("%d",&choice);
        for (i=0;i<std_no;i++)
        {
            printf("\t\t\tStudent %d ID: ",i+1);
            scanf("%d",&ID);
            if (Search (ID,&s))
                update_Score (ID,choice,&s);
            else
                printf("ID is NOT Exist");
        }
        break;
    case 7:
        CleareStack(&s);
      default:
      return 0;
    }
    }
    return 0;
}



