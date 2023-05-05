#ifndef FINAL_H
#define FINAL_H

struct Studentinfo
{
    char StudentID[50];
    char Full_name[50];
    char Birthdate[50];
    float Algebra;
    float Calculus;
    float Basic_Programming;
};

void findoldest(struct Studentinfo sv[], int n);
void findyoungest(struct Studentinfo sv[],int n);
#endif
