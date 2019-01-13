/**
 * 输入一个日期（yyyy/mm/dd）如果定义这一年的1月1日为第一天，那么这一天是这一年的第几天
*/
#include<cstdio>
#include<iostream>
using namespace std;

int month1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};// 平年
int month2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};// 闰年

int slove(int y,int m,int d)
{
    bool flg=false;// 默认为平年
    int ans=0;
    if((y%4==0&&y%100!=0)||y%400==0) flg=true;// 如果是闰年，修改成闰年的标志
    for(int i=1;i<m;i++)ans+=flg==true?month2[i]:month1[i];
    return ans+d;
}
int main()
{
    int y,m,d;
    scanf("%d %d %d",&y,&m,&d);
    printf("%d\n",slove(y,m,d));
    return 0;
}
