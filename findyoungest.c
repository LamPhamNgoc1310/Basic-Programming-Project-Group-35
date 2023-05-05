#include "final.h"
#include <stdio.h>
#include <string.h>

void findyoungest(struct Studentinfo sv[],int n)
{
    int maxx=0,vtyoungest;
    for(int i=0;i<n;i++)
    {
        int t=0,mangvt[3],d=0;
        char s[50];
        strcpy(s,sv[i].Birthdate);
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]<'0'||s[j]>'9')
            {
                mangvt[++d]=j;
            }
        }
        int vt1=mangvt[1];
        int vt2=mangvt[2];
        for(int k=vt2+1;k<strlen(s);k++)
        {
            t=t*10+((int)(s[k])-48);
        }
        if(vt2-vt1-1==2)
        {
            for(int l=vt1+1;l<vt2;l++)
            {
                t=t*10+((int)(s[l])-48);
            }
        }
        else
        {
            t=t*100+((int)(s[vt2-1])-48);
        }
        if(vt1-0==2)
        {
            for(int m=0;m<vt1;m++)
            {
                t=t*10+((int)(s[m])-48);
            }
        }
        else
        {
            t=t*100+(int)(s[0]-48);
        }
        if(maxx<t)
        {
            maxx=t;
            vtyoungest=i;
        }
    }
    printf("The youngest Student is: \n");
    printf("StudentID: %s\n",sv[vtyoungest].StudentID);
    printf("Full_name: %s\n",sv[vtyoungest].Full_name);
    printf("Birthdate: %s\n",sv[vtyoungest].Birthdate);
}