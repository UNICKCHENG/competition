#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
// zhicheng
// January,26,2019
// 0,1,2,3,4,5,6,7,8,9基础模板
string dic[]={
   " -     -  -     -  -  -  -  - ",
   "| |  |  |  || ||  |    || || |",
   "       -  -  -  -  -     -  - ", 
   "| |  ||    |  |  || |  || |  |",
   " -     -  -     -  -     -  - ",
};


// 将一串数字按比例打印出来
inline void print(int s,char* n)
{
    for(int i=0;n[i]!='\0';i++)
    {
        if(i!=0) printf(" ");
        printf(" ");
        for(int j=0;j<s;j++) printf("%c",dic[0][(n[i]-'0')*3+1]);
        printf(" ");
    }
    printf("\n");

    for(int i=0;i<s;i++)
    {
        for(int i=0;n[i]!='\0';i++)
        {
            if(i!=0) printf(" ");
            printf("%c",dic[1][(n[i]-'0')*3]);
            for(int i=0;i<s;i++) printf(" ");
            printf("%c",dic[1][(n[i]-'0')*3+2]);
        }
        printf("\n");
    }

    for(int i=0;n[i]!='\0';i++)
    {
        if(i!=0) printf(" ");
        printf(" ");
        for(int j=0;j<s;j++) printf("%c",dic[2][(n[i]-'0')*3+1]);
        printf(" ");
    }
    printf("\n");

    for(int i=0;i<s;i++)
    {
        for(int i=0;n[i]!='\0';i++)
        {
            if(i!=0) printf(" ");
            printf("%c",dic[3][(n[i]-'0')*3]);
            for(int i=0;i<s;i++) printf(" ");
            printf("%c",dic[3][(n[i]-'0')*3+2]);
        }
        printf("\n");
    }

    for(int i=0;n[i]!='\0';i++)
    {
        if(i!=0) printf(" ");
        printf(" ");
        for(int j=0;j<s;j++) printf("%c",dic[4][(n[i]-'0')*3+1]);
        printf(" ");
    }
    printf("\n");
}


int main()
{
    // freopen("test_case/2.in","r",stdin);
    // freopen("test_case/2.out","w",stdout);
    int s;char n[9];bool first=true;
    while(scanf("%d %s",&s,n)!=EOF&&s) 
    {
        if(!first) printf("\n");
        else first=false;
        print(s,n);
    }
    return 0;
}