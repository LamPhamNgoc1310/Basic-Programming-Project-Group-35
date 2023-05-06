#include <stdio.h>
#include "final.h"
int main()
{
    struct Studentinfo sv[1000];
    int n;
    char *filename = "FINAL.txt";
    printf("The number of students in the group is: ");
    scanf("%d",&n);
    input(sv,n);
    output(sv,n);
    highestGPA(sv,n);
    lowestGPA(sv,n);
    highestBP(sv,n);
    write_to_file(filename,sv,n);
    Printfirstname(sv,n);
    findoldest(sv,n);
    findyoungest(sv,n);
    searchID(sv,n);
    sortlist(sv,n);
    return 0;
}
