/**
 * 日期问题
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// zhicheng
typedef struct date{
    int y;
    int m;
    int d;
}D;
D da[5];
int month1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};// 平年
int month2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};// 闰年
bool cmp(D a,D b)
{
    if(a.y!=b.y) return a.y<b.y;
    if(a.m!=b.m) return a.m<b.m;
    return a.d<b.d;
}

bool judge(int y,int m,int d)
{// 判断y/m/d这个日期是否有效
    // 初步判读
    if(y<1960||y>2059) return false;
    if(m<1||m>12) return false;
    if(d<1||d>31) return false;
    // 精确判断
    if((y%4==0&&y%100!=0)||(y%400==0)) {if(d>month2[m]) return false;}
    else if(d>month1[m]) return false;
    return true;
}
int main()
{
    int a,b,c;
    int y,m,d,cnt=0;
    scanf("%d/%d/%d",&a,&b,&c);
    if(a==b&&b==c)
    {
        y=a+(a<60?2000:1900);m=b;d=c;
        if(judge(y,m,d)) {da[cnt].y=y;da[cnt].m=m;da[cnt].d=d;cnt++;}
    }
    else if(a==b)
    {
        // 年月日
        y=a+(a<60?2000:1900);m=b;d=c;
        if(judge(y,m,d)) {da[cnt].y=y;da[cnt].m=m;da[cnt].d=d;cnt++;}
        // 月日年/日月年
        y=c+(c<60?2000:1900);m=a;d=b;
        if(judge(y,m,d)) {da[cnt].y=y;da[cnt].m=m;da[cnt].d=d;cnt++;}
    }
    else
    {   
        // 年月日
        y=a+(a<60?2000:1900);m=b;d=c;
        if(judge(y,m,d)) {da[cnt].y=y;da[cnt].m=m;da[cnt].d=d;cnt++;}
        // 月日年
        y=c+(c<60?2000:1900);m=a;d=b;
        if(judge(y,m,d)) {da[cnt].y=y;da[cnt].m=m;da[cnt].d=d;cnt++;}
        // 日月年
        y=c+(c<60?2000:1900);m=b;d=a;
        if(judge(y,m,d)) {da[cnt].y=y;da[cnt].m=m;da[cnt].d=d;cnt++;}
    }
    sort(da,da+cnt,cmp);
    for(int i=0;i<cnt;i++)
    {
        printf("%04d-%02d-%02d\n",da[i].y,da[i].m,da[i].d);
    }
    return 0;
}