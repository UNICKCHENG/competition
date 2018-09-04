/**
 * 1085 PAT单位排行(25)
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805260353126400
 * 解题思路:PAT-B最喜欢考察的排序问题,对于面对此类题目时,一般需要用到map映射和sort算法
 *          (1)用map映射将每个学校进行编号并将需要的学生信息存入进去
 *          (2)这题还有个输出格式的问题,发现这也是PAT在排序问题中喜欢考察的,需要注意技巧
 */
#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<cctype>
using namespace std;

// zhicheng
// September,4,2018
struct D{string id;int a;int b;int t;int sco;int num;};D d[100005];
map<string,int> ma;
int cn=0;
bool comp(D& a,D& b)
{
    a.sco=(int)(a.b*1.0/1.5+a.a+a.t*1.5);
    b.sco=(int)(b.b*1.0/1.5+b.a+b.t*1.5);
    if(a.sco!=b.sco) return a.sco>b.sco;
    else if(a.num!=b.num) return a.num<b.num;
    else return a.id<b.id;
}
int main()
{
    // freopen("1.in","r",stdin);
    int n;string stu,id;int sco;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>stu>>sco>>id;
        for(int j=0;j<id.length();j++) id[j]=tolower(id[j]);
        if(ma[id]==0) {ma[id]=++cn;d[cn].a=d[cn].b=d[cn].t=d[cn].num=0;}
        d[ma[id]].id=id;
        d[ma[id]].num++;
        switch(stu[0])
        {
            case 'A':d[ma[id]].a+=sco;break;
            case 'B':d[ma[id]].b+=sco;break;
            case 'T':d[ma[id]].t+=sco;break;
        }
    }
    sort(d+1,d+cn+1,comp);
    printf("%d\n",cn);
    for(int i=1,j;i<=cn;i=j)
    {
        j=i;
        while(j<=cn&&d[i].sco==d[j].sco)
        {
            cout<<i<<" "<<d[j].id<<" "<<d[j].sco<<" "<<d[j].num<<endl;
            j++; 
        }
    }
    return 0;
}