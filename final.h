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
void input(struct Studentinfo sv[],int n);
void output(struct Studentinfo sv[],int n);
void highestGPA(struct Studentinfo sv[],int n);
void lowestGPA(struct Studentinfo sv[],int n);
void highestBP(struct Studentinfo sv[],int n);
void Printfirstname(struct Studentinfo sv[],int n);
void searchID(struct Studentinfo sv[],int n);
void sortlist(struct Studentinfo sv[],int n);
void write_to_file(char* filename, struct Studentinfo sv[], int n);
#endif
