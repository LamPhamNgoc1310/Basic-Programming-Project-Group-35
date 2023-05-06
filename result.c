#include <stdio.h>
#include <string.h>
#include "final.h"
#include <stdbool.h>

char headers[7][100]={"StudentID","Full_Name","Birthdate","Algebra","Calculus","Basic_Programming","GPA"};
bool ktbirthdate(char bd[])
{
    int mangvtct[3],cnt=0,ts=0,ts1=0,ts2=0;
    for(int i=0;i<strlen(bd);i++)
    {
        if((bd[i]<'0'||bd[i]>'9')&&bd[i]!=' '&&bd[i]!='/')
        {
            return false;
        }
    }
    for (int i=0;i<strlen(bd);i++)
    {
        if(bd[i]<'0'||bd[i]>'9')
        {
            mangvtct[++cnt]=i;
        }
    }
    if(cnt!=2)
    {
        return false;
    }
    for (int i=mangvtct[2]+1;i<strlen(bd);i++)
    {
        ts=ts*10+(int)bd[i]-'0';
    }
    for (int i=mangvtct[1]+1;i<mangvtct[2];i++)
    {
        ts1=ts1*10+(int)bd[i]-'0';
    }
    for (int i=0;i<mangvtct[1];i++)
    {
        ts2=ts2*10+(int)bd[i]-'0';
    }
    if (ts%4==0&&ts%100!=0||ts%400==0)
    {
        if (ts1<=7&&ts1>=1)
        {
            
            if (ts1==2)
            {
                if (ts2<=29&&ts2>=1)
                {
                    return true;
                }
            }
            else 
            {
                if (ts1%2!=0)
                {
                    if (ts2>=1&&ts2<=31)
                    {
                        return true;
                    }
                }
                else 
                {
                    if (ts2>1&&ts2<=30)
                    {   
                        return true;
                    }
                }
            }
        }
        else 
        {
            if (ts1<=12)
            {
                if (ts1%2==0)
                {
                    if (ts2>=1&&ts2<=31)
                    {
                        return true;
                    }
                }
                else 
                {
                    if (ts2>1&&ts2<=30)
                    {
                        return true;
                    }
                }
            }
        }
    }
    else 
    {
        if (ts1<=7&&ts1>=1)
        {
            
            if (ts1==2)
            {
                if (ts2<=28&&ts2>=1)
                {
                    return true;
                }
            }
            else if (ts1%2!=0)
            {
                if (ts2>=1&&ts2<=31)
                {
                    return true;
                }
            }
            else if (ts2>1&&ts2<=30)
            {
                return true;
            }
        }
        else
        {
            if (ts1<=12)
            {
                if (ts1%2==0)
                {
                    if (ts2>=1&&ts2<=31)
                    {
                        return true;
                    }
                }
                else 
                {
                    if (ts2>1&&ts2<=30)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
void Swap1(float *a,float *b)
{
    float tg;
    tg=*a;
    *a=*b;
    *b=tg;
}
void Swap2(int *cc,int *dd)
{
    float temp;
    temp=*cc;
    *cc=*dd;
    *dd=temp;
}
void input(struct Studentinfo sv[],int n)
{
    if(n>1000)
    {
        while(n>1000)
        {
            if(n>1000)
            {
                printf("Please fill again \n");
                printf("The number of students in the group is: ");
                scanf("%d",&n);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("Student no %d \n",i+1);
        printf("StudentID: ");
        fflush(stdin);
        gets(sv[i].StudentID);
        printf("Full_name: ");
        fflush(stdin);
        gets(sv[i].Full_name);
        printf("Birthdate(Day/Month/Year): ");
        fflush(stdin);
        gets(sv[i].Birthdate);
        if (ktbirthdate(sv[i].Birthdate)==false)
        {
            do 
            {
                printf("Invalid birthdate, try again: ");
                fflush(stdin);
                gets(sv[i].Birthdate);
            } 
            while (ktbirthdate(sv[i].Birthdate)==false);
        }
        printf("Overall grades of Algebra: ");
        scanf("%f",&sv[i].Algebra);
        printf("Overall grades of Calculus: ");
        scanf("%f",&sv[i].Calculus);
        printf("Overall grades of Basic_Programming: ");
        scanf("%f",&sv[i].Basic_Programming);
        printf("\n");
    }
}
void output(struct Studentinfo sv[],int n)
{
    printf("We have table: \n");
    printf("%-12s\t%-20s\t%-11s\t%-9s\t%-10s\t%-19s\t%-3s\n",headers[0],headers[1],headers[2],headers[3],headers[4],headers[5],headers[6]);
    for(int i=0;i<n;i++)
    {
         printf("%-12s\t%-20s\t%-11s\t%-9.1f\t%-10.1f\t%-19.1f\t%-3.1f\n",sv[i].StudentID,sv[i].Full_name,
         sv[i].Birthdate,sv[i].Algebra,sv[i].Calculus,sv[i].Basic_Programming,
         (sv[i].Algebra+sv[i].Calculus+sv[i].Basic_Programming)/3);
    }
    printf("\n");
}
void write_to_file(char* filename, struct Studentinfo sv[], int n) 
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening the file %s", filename);
        return;
    }
    fprintf(fp,"We have table: \n");
    fprintf(fp,"%-12s\t%-20s\t%-11s\t%-9s\t%-10s\t%-19s\t%-3s\n",headers[0],headers[1],headers[2],headers[3],headers[4],headers[5],headers[6]);
    for(int i=0;i<n;i++)
    {
         fprintf(fp,"%-12s\t%-20s\t%-11s\t%-9.1f\t%-10.1f\t%-19.1f\t%-3.1f\n",sv[i].StudentID,sv[i].Full_name,
         sv[i].Birthdate,sv[i].Algebra,sv[i].Calculus,sv[i].Basic_Programming,
         (sv[i].Algebra+sv[i].Calculus+sv[i].Basic_Programming)/3);
    }
    fclose(fp);
}
void highestGPA(struct Studentinfo sv[],int n)
{
    int mangten1[101];
    printf("The student(s) has the highest GPA is/are: ");
    float maxx=0;
    int vt,d=0;
    for(int i=0;i<n;i++)
    {
        float t=0;
        t=t+sv[i].Algebra+sv[i].Calculus+sv[i].Basic_Programming;
        if(maxx<t)
        {
            maxx=t;
        }
    }
    for(int i=0;i<n;i++)
    {
        float tong=0;
        tong=tong+sv[i].Algebra+sv[i].Calculus+sv[i].Basic_Programming;
        if(maxx==tong)
        {
            mangten1[++d]=i;
        }
    }
    printf("%s",sv[mangten1[1]].Full_name);
    for(int i=2;i<=d;i++)
    {
        printf(", %s",sv[mangten1[i]].Full_name);
    }
    printf(" with %.1f score",maxx/3);
    printf("\n");
}
void lowestGPA(struct Studentinfo sv[],int n)
{
    int mangten2[101];
    printf("The student(s) has the lowest GPA is/are: ");
    float minn=999;
    int d=0;
    for(int i=0;i<n;i++)
    {
        float t=0;
        t=t+sv[i].Algebra+sv[i].Calculus+sv[i].Basic_Programming;
        if(minn>t)
        {
            minn=t;
        }
    }
    for(int i=0;i<n;i++)
    {
        float tong=0;
        tong=tong+sv[i].Algebra+sv[i].Calculus+sv[i].Basic_Programming;
        if(minn==tong)
        {
            mangten2[++d]=i;
        }
    }
    printf("%s",sv[mangten2[1]].Full_name);
    for(int i=2;i<=d;i++)
    {
        printf(", %s",sv[mangten2[i]].Full_name);
    }
    printf(" with %.1f score",minn/3);
    printf("\n");
}
void highestBP(struct Studentinfo sv[],int n)
{
    int mangten3[101];
    printf("The student(s) with the highest score in Basic_Programming is/are: ");
    float max1=0;
    int d=0;
    for(int i=0;i<n;i++)
    {
        if(max1<sv[i].Basic_Programming)
        {
            max1=sv[i].Basic_Programming;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(sv[i].Basic_Programming==max1)
        {
            mangten3[++d]=i;
        }
    }
    printf("%s",sv[mangten3[1]].Full_name);
    for(int i=2;i<=d;i++)
    {
        printf(", %s",sv[mangten3[i]].Full_name);
    }
    printf(" with %.1f score",max1);
    printf("\n");
}
void Printfirstname(struct Studentinfo sv[],int n)
{
    printf("First name of each student: ");
    int vtc;
    for(int i=0;i<n;i++)
    {
        printf("%d.",i+1);
        char x[50];
        strcpy(x,sv[i].Full_name);
        for(int j=strlen(x)-1;j>=0;j--)
        {
            if(x[j]==' ')
            {
                vtc=j;
                break;
            }
        }
        for(int k=vtc+1;k<strlen(x);k++)
        {
            printf("%c",x[k]);
        }
        printf(" ");
    }
    printf("\n");
    printf("\n");
}
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
    printf("\n");
}
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
    printf("\n");
}
void searchID(struct Studentinfo sv[],int n)
{
    int flag=0,vtct;
    char IDSV[50];
    printf("Please fill the ID that you want: ");
    scanf("%s",IDSV);
    for(int i=0;i<n;i++)
    {
        if(strcmp(IDSV,sv[i].StudentID)==0)
        {
            flag=1;
            vtct=i;
            break;
        }
    }
    if(flag==1)
    {
        printf("The student you are searching for is: \n");
        printf("StudentID: %s\n",sv[vtct].StudentID);
        printf("Full_name: %s\n",sv[vtct].Full_name);
        printf("BirthDate: %s\n",sv[vtct].Birthdate);
        printf("Algebra score: %.1f\n",sv[vtct].Algebra);
        printf("Calculus score: %.1f\n",sv[vtct].Calculus);
        printf("Basic Programming score: %.1f\n",sv[vtct].Basic_Programming);
        printf("GPA: %.1f\n",(sv[vtct].Algebra+sv[vtct].Calculus+sv[vtct].Basic_Programming)/3);
    }
    if(flag==0)
    {
        printf("\n");
        printf("there is no matched ID");
        printf("\n");
    }
    printf("\n");
}
void sortlist(struct Studentinfo sv[],int n)
{
    float a[50];
    int mangvitri[50];
    int d=0,dem=0;
    float t;
    for(int i=0;i<n;i++)
    {
        t=sv[i].Algebra+sv[i].Calculus+sv[i].Basic_Programming;
        a[++d]=t;
    }
    for(int i=1;i<=d;i++)
    {
        mangvitri[i]=i;
    }
    for(int i=1;i<=d;i++)
    {
        float minn=100;
        int vt;
        for(int j=i+1;j<=d;j++)
        {
            if(minn>a[j])
            {
                minn=a[j];
                vt=j;
            }
        }
        if(minn<a[i])
        {
            Swap1(&a[i],&a[vt]);
            Swap2(&mangvitri[i],&mangvitri[vt]);
        }
    }
    printf("Sortlist follow GPA: \n");
    printf("%-12s\t%-20s\t%-11s\t%-9s\t%-10s\t%-19s\t%-3s\n",headers[0],headers[1],headers[2],headers[3],headers[4],headers[5],headers[6]);
    for(int i=1;i<=d;i++)
    {
         printf("%-12s\t%-20s\t%-11s\t%-9.1f\t%-10.1f\t%-19.1f\t%-3.1f\n",sv[mangvitri[i]-1].StudentID,sv[mangvitri[i]-1].Full_name,sv[mangvitri[i]-1].Birthdate,
                sv[mangvitri[i]-1].Algebra,sv[mangvitri[i]-1].Calculus,sv[mangvitri[i]-1].Basic_Programming,a[i]/3);
    }
}