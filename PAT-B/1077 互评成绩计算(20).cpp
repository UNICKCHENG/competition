/**
 * 1077 互评成绩计算(20)
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805262303477760
 * 解题思路:注意在处理G2的时候,计算全部数,最后减去最大和最小数即可,不过这一步的前提是保证G2的求和数不少于2个,题意说N>3,正好是满足这个条件的 
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// September,5,2018
int main()
{
    // freopen("1.in","r",stdin);
    int n,m,g1,g2,_;
    for(scanf("%d %d",&n,&m),_=n;_;_--)
    {
        int maxx=-1,minn=101,tmp,num=0;
        scanf("%d",&g1); g2=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d",&tmp);
            if(tmp<0||tmp>m)continue;
            if(tmp>maxx) maxx=tmp;
            if(tmp<minn) minn=tmp;
            g2+=tmp;
            num++;
        }
        g2=(g2-maxx-minn)/(num-2);
        printf("%d\n",(int)((g1+g2)/2.0+0.5));
    }
    return 0;
}