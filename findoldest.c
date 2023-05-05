#include "final.h"
#include <stdio.h>
#include <string.h>


void findoldest(struct Studentinfo sv[],int n)
{
    int minn=1e9,vtoldest;
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
            t=t*10+ (int)(s[k])-48 ;
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
        if(minn>t)
        {
            minn=t;
            vtoldest=i;
        }
    }
    printf("The oldest Student is: \n");
    printf("StudentID: %s\n",sv[vtoldest].StudentID);
    printf("Full_name: %s\n",sv[vtoldest].Full_name);
    printf("Birthdate: %s\n",sv[vtoldest].Birthdate);
}