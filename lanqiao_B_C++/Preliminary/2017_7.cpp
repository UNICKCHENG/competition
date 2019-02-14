/**
 * 日期问题
 * 解题思路: 模拟题。
 * 给定一个日期，最多三种情况（年月日，日月年，月日年）通过函数把每种情况尝试一遍，如果满足，则存入数组。对数组进行排序，按从早到晚输出日期
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// zhicheng
// February,15,2019
typedef struct date
{
    int y;
    int m;
    int d;
}D;
vector<D> ans;

int month1[]={0,31,29,31,30,31,30,31,31,30,31,30,31};// 闰年
int month2[]={0,31,28,31,30,31,30,31,31,30,31,30,31};// 平年

bool judge(int y,int m,int d)
{// 判断这样的年月日是否合法
    y+=y>=60?1900:2000;
    if(1960>y||y>2059) return false;
    if(m<1||m>12) return false;
    if((y%4==0&&y!=100)||(y%400==0)) {if(d<1||d>month1[m]) return false;}
    else {if(d<1||d>month2[m]) return false;}
    return true;
}
bool cmp(D a,D b)
{// 给合法的日期按小到大排序
    if(a.y!=b.y) return a.y<b.y;
    if(a.m!=b.m) return a.m<b.m;
    if(a.d!=b.d) return a.d<b.d;
}
int main()
{
    int a,b,c;
    scanf("%d/%d/%d",&a,&b,&c);
    if(a==b&&b==c) {if(judge(a,b,c)) ans.push_back({a>=60?1900+a:2000+a,b,c});}
    else if(a==b)
    {
        if(judge(a,b,c)) ans.push_back({a>=60?1900+a:2000+a,b,c});// 年月日
        if(judge(c,b,a)) ans.push_back({c>=60?1900+c:2000+c,b,a});// 日月年/月日年
    }
    else 
    {
        if(judge(a,b,c)) ans.push_back({a>=60?1900+a:2000+a,b,c});// 年月日
        if(judge(c,a,b)) ans.push_back({c>=60?1900+c:2000+c,a,b});// 月日年
        if(judge(c,b,a)) ans.push_back({c>=60?1900+c:2000+c,b,a});// 日月年
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0,len=ans.size();i<len;++i) 
        printf("%04d-%02d-%02d\n",ans[i].y,ans[i].m,ans[i].d);
    return 0;
}