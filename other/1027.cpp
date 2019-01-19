#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int mon1[]={31,29,31,30,31,30,31,31,30,31,30,31};
int mon2[]={31,28,31,30,31,30,31,31,30,31,30,31};

int count(char* a,char* b)
{// a和b表示日期，a的日期比b的日期小
    int y1,y2,m1,m2,d1,d2,ans=0;
    y1=(a[0]-'0')*1000+(a[1]-'0')*100+(a[2]-'0')*10+(a[3]-'0');
    m1=(a[5]-'0')*10+(a[6]-'0');
    d1=(a[8]-'0')*10+(a[9]-'0');
    y2=(b[0]-'0')*1000+(b[1]-'0')*100+(b[2]-'0')*10+(b[3]-'0');
    m2=(b[5]-'0')*10+(b[6]-'0');
    d2=(b[8]-'0')*10+(b[9]-'0');
    for(int i=y1;i<y2;i++)
    {// 从y1年开始到y2年之间，统计天数
        if((i%4==0&i%100!=0)||(i%400==0)) ans+=366;// 闰年
        else ans+=365;// 平年
    }
    for(int i=1;i<m2;i++)
    {// 统计y2年的1月1日距离m2月d2日相隔的天数
        if((y2%4==0&&y2%100!=0)||(y2%400==0)) ans+=mon1[i-1];
        else ans+=mon2[i-1];
    }
    for(int i=1;i<m1;i++)
    {// 统计y1年的1月1日距离m1月d1日相隔的天数
        if((y1%4==0&&y1%100!=0)||(y1%400==0)) ans-=mon1[i-1];
        else ans-=mon2[i-1];
    }
    return ans-d1+d2;
}
int main()
{
    // freopen("1.in","r",stdin);
    char a[12],b[12];
    scanf("%s %s",a,b);
    printf("%d\n",strcmp(a,b)>0?count(b,a):count(a,b));
    return 0;
}