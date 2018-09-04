/**
 * 1082 射击比赛(20)
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805260990660608
 * 解题思路:数学问题,计算点(x,y)到点(0,0)的距离
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// September,4,2018
int main()
{
    int n,id,x,y,id_max,id_min,maxx=-1,minn=20005;
    for(scanf("%d",&n);n;n--)
    {
        scanf("%d %d %d",&id,&x,&y);
        if((x*x+y*y)>maxx) {id_max=id;maxx=x*x+y*y;}
        if((x*x+y*y)<minn) {id_min=id;minn=x*x+y*y;}
    }
    printf("%04d %04d\n",id_min,id_max);
    return 0;
}