#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include "string.h"


typedef struct Birth{
    int day;
    int month;
    int year;
}Birth;

typedef struct Score {
    float math;
    float english;
    float cs;
}Score;

typedef struct info {
    short int ID;
    char phone [12];
    char name [50];
    char address [200];
    Score score;
    Birth birthday;
}info;


typedef struct StackNode {
    info Student;
    struct StackNode *next;
}StackNode;

typedef struct Stack {
    StackNode *Top;
    int Size;
}Stack;

void Add_Student(info, Stack *);
void Edit_Student(int, char, Stack *);
void Delete_Student (int, Stack *);
void Student_list(Stack *);
void Rank_Student(Stack *);
void update_Score(int, char, Stack *);
bool Search(int, Stack *);
void CreateStack (Stack *);
int StackEmpty(Stack *);
void CleareStack(Stack *);
void Student_Sort(Stack *);
//void exit (int);
#endif // HEADER_H_INCLUDED
