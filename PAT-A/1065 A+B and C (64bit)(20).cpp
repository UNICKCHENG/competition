/**
 * 1065 A+B and C (64bit)(20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805406352654336
 * 题目大意:给定三个[-20^63,20^63]区间内的数字A,B,C,判断是否满足A+B>C
 * 解题思路:模拟题.如果A和B同号,相加的结果与他们不同号,则说明溢出;如果不同号,则无需考虑会溢出的问题
 */

#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// September 26,2018
int main()
{
    long long int a,b,c;
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("Case #%d: ",i);
        long long int sum=a+b;
        if(a>0&&b>0&&sum<0) printf("true\n");
        else if(a<0&&b<0&&sum>=0) printf("false\n");
        else sum>c?printf("true\n"):printf("false\n");
    }
    return 0;
}

// the older code
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// September 26,2018
int main()
{
    int n;scanf("%d",&n);
    long long int a,b,c;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("Case #%d: ",i);
        if(a==0&&b==0&&c==0) printf("false\n");// 存在等于0的特殊情况处理
        else if(a==0) b>c?printf("true\n"):printf("false\n");
        else if(b==0) a>c?printf("true\n"):printf("false\n");
        else if(c==0) 
        {
            if((a>0&&b>0)||(a<0&&b<0)) (a>0&&b>0)?printf("true\n"):printf("false\n");
            else a+b>0?printf("%lld,%lld,1true\n",a,b):printf("%lld,%lld,1false\n",a,b);
        }
        else if((a>0&&c>0) || (a<0&&c<0)) b>c-a?printf("true\n"):printf("false\n");// 用是否同号处理一般性的数据
        else if((b>0&&c>0) || (b<0&&c<0)) a>c-b?printf("true\n"):printf("false\n");
        else if((a>0&&b>0)||(a<0&&b<0)) c<0?printf("true\n"):printf("false\n");
    }
    return 0;
}

