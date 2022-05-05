#include "header.h"
void CreateStack (Stack *ps)
{
    ps->Top=NULL;
    ps->Size=0;
    printf("Stack Created Successfully");
}

int StackEmpty(Stack *ps)

{
    return ps->Top==NULL;
    printf("Stack is Empty");
}

void CleareStack (Stack *ps)
{
    StackNode *pn=ps->Top;
    StackNode *qn=ps->Top;
  while(pn)
    {
        pn=pn->next;
        free(qn);
        qn=pn;
    }
  ps->Top=NULL;
}


void Add_Student(info Data, Stack *ps)   //Push Function
{
    StackNode *pn = (StackNode *) malloc (sizeof(StackNode));
    pn->Student=Data;
    pn->next=ps->Top;
    ps->Top=pn;
    ps->Size++;
}


void Edit_Student (int ID, char choice ,Stack *ps)  //Pop Function with Editing
{
    StackNode *pn=ps->Top;
    while (pn->Student.ID!=ID)
    {
        pn=pn->next;
    }
        switch (choice)
        {
            //case 86:
                //printf("Current Score is: %f",pn->Student.score);
                //printf("\nPlease Enter New Score: ");
                //scanf("%f",pn->Student.score);
                //printf("Score After Editing: %d",pn->Student.score);
                //printf("Edited Successfully");
              //  break;
            case 1:
                printf("Current Phone is: %s",pn->Student.phone);
                printf("\nPlease Enter New Phone: ");
                scanf("%s",pn->Student.phone);
                printf("Phone After Editing: %s",pn->Student.phone);
                printf("Edited Successfully");
                break;
            case 2:
                printf("Current Address is: %s",pn->Student.address);
                printf("\n Please Enter New Address: ");
                scanf("%c",pn->Student.address);
                fgets(pn->Student.address,200,stdin);
                printf("Address After Editing: %s\n",pn->Student.address);
                printf("\n Edited Successfully");
                break;
        }
}
void Student_list(Stack *ps)
{
    StackNode *pn=ps->Top;
    printf("\tID\t\tName\tPhone\taddress\tBirthday\tMath\tenglish\tcs\n");
    while (pn!= NULL)
    {
       printf("\t%d\t\t%s\t%s\t%s\t%d/%d/%d\t%f\t%f\t%f\n",pn->Student.ID,pn->Student.name,pn->Student.phone,pn->Student.address
                                                ,pn->Student.birthday.day,pn->Student.birthday.month,pn->Student.birthday.year,
                                                pn->Student.score.math,pn->Student.score.english,pn->Student.score.cs);
        pn=pn->next;
    }

}
bool Search (int ID, Stack *ps)
{
    StackNode *pn=ps->Top;
    while (pn!= NULL)
    {
        if (pn->Student.ID == ID)
            return true;
        pn=pn->next;
    }
    return false;
}


void Delete_Student (int ID, Stack *ps)
{

    StackNode *pn=ps->Top;
    StackNode *prev=ps->Top;
    while (pn->Student.ID!=ID)
    {
        prev=pn;
        pn=pn->next;
    }

    prev->next=pn->next;
    free(pn);
    ps->Size--;
}

void Rank_Student(Stack *ps)
{

int choice=1;
printf("Do you want sort all students in:");
printf("\n\t\t\t1. Ascending order");
printf("\n\t\t\t2. Descending order");
 printf("\n\n\t\t\tMy Option is: ");
scanf("%d",&choice);

    StackNode *current=ps->Top;
    StackNode *index=NULL;
    info temp;

if(current==NULL)
    return;
else
{
    switch(choice)
    {
    case 1://1. Ascending order
    while (current!=NULL)
    {
        index=current;
        while (index->next!=NULL)
        {
            if (index->Student.score.cs > index->next->Student.score.cs)
            {
                temp=index->Student;
                index->Student=index->next->Student;
                index->next->Student=temp;
            }
            index = index->next;
            if (index==NULL) break;
        }
        current = current->next;

    }
        break;
    case 2: // 2. Descending order
    while (current!=NULL)
    {
        index=current;
        while (index->next!=NULL)
        {
            if (index->Student.score.cs < index->next->Student.score.cs)
            {
                temp=index->Student;
                index->Student=index->next->Student;
                index->next->Student=temp;
            }
            index = index->next;
            if (index==NULL) break;
        }
         current = current->next;

    }
        break;
    }
}
}
void update_Score(int ID, char choice ,Stack *ps)  //Pop Function with Editing

{

    StackNode *pn=ps->Top;
    float mathS;
     float englishS;
      float csS;
    if(pn==NULL) return;
    while (pn->Student.ID!=ID)
    {
        pn=pn->next;
    }

         switch (choice)
        {
        case 1:

            printf("Current Math Score is: %f",pn->Student.score.math);
            printf("\nPlease Enter New Math Score: ");
            scanf("%f",&mathS);
            pn->Student.score.math=mathS;
            printf("Math Score After updating: %f\n",pn->Student.score.math);
            printf("update Successfully");
            break;
        case 2:

            printf("Current english score is: %f",pn->Student.score.english);
            printf("\nPlease Enter New english Score: ");
            scanf("%f",&englishS);
            pn->Student.score.english=englishS;
            printf("english score After updating: %f\n",pn->Student.score.english);
            printf("update Successfully");
            break;
        case 3:

            printf("Current cs score is: %f",pn->Student.score.cs);
            printf("\n Please Enter New cs Score: ");
            scanf("%f",&csS);
             pn->Student.score.cs=csS;
            printf("cs After updating: %f\n",pn->Student.score.cs);
            printf("\n update Successfully");
            break;
        }
}

void Student_Sort(Stack *ps)
{
    StackNode *current=ps->Top;
    StackNode *index=NULL;
    info temp;
    printf("studet sort function is called\n");

    while (current!=NULL)
    {
        index=current;
        while (index->next!=NULL)
        {
            char c1=index->Student.name[0];
            char c2=index->next->Student.name[0];
            if (c1>c2)
            {
                temp=index->Student;
                index->Student=index->next->Student;
                index->next->Student=temp;
            }
            index = index->next;
            if (index==NULL) return;
        }
        current = current->next;

    }
}
