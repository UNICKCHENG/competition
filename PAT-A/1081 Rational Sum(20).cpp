/**
 * 1081 Rational Sum(20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805386161274880
 * 题目大意：给定N个分数，计算他们的和，输出结果保证是一个真分数
 * 解题思路：最大公约数。利用最大公约数求法将这N个分数相加，接下来利用对分数的处理，将其化简成一个真分数
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// October,31,2018
inline long int gcd(long int x,long int y){return y==0?x:gcd(y,x%y);}

int main()
{
    int n,a,b,ta,tb,tmp;a=b=0;
    for(scanf("%d",&n);n;n--)
    {
        scanf("%d/%d",&ta,&tb);
        if(a==0){a=ta;b=tb;continue;}
        tmp=gcd(b,tb);
        a=a*tb/tmp+ta*b/tmp;
        b=b*tb/tmp;
        tmp=gcd(a,b);// 化简分数
        a/=tmp;b/=tmp;
    }
    tmp=a/b;a-=tmp*b;
    if(tmp)
    {// 假分数处理
        printf("%d",tmp);
        if(a)printf(" %d/%d",a,b);
    }  
    else if(a)printf("%d/%d",a,b); // 正分数处理
    else printf("0"); // 为0的特殊情况处理
    printf("\n");
    return 0;
}