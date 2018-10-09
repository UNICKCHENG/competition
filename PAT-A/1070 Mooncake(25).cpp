/**
 * 1070 Mooncake(25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805399578853376
 * 题目大意:给定不同种类月饼的数量和价格,现在市场需求一定数量的月饼,那么如何保证收益最大
 * 解题思路:贪心算法.求出每种月饼单价,先售出单价最高的月饼,这样一来保证了收益最高,但需要注意的是,题目未说月饼总数是整数,因为单位也不是以个数开始的
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// zhicheng
// Octobrer,9,2018
typedef struct{double num;double prices;}D; 
D d[1005];
bool comp(D a,D b){return (a.prices/a.num)>(b.prices/b.num);}
int main()
{
    int n;double k,re=0;scanf("%d %lf",&n,&k);
    for(int i=0;i<n;i++) scanf("%lf",&d[i].num);
    for(int i=0;i<n;i++) scanf("%lf",&d[i].prices);
    sort(d,d+n,comp);
    for(int i=0;k&&i<n;i++)
    {
        if(k>=d[i].num) {k-=d[i].num;re+=d[i].prices;}
        else {re+=(d[i].prices/d[i].num)*k;break;}
    }
    printf("%.2lf\n",re);
    return 0;
}