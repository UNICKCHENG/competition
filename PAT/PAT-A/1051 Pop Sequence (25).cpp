/**
 * 1051 Pop Sequence (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805427332562944
 * 题目大意:有个容量限制为m的栈，分别把1，2，3，…，n入栈,，问是否可以得到给定的出栈顺序
 * 解题思路:栈操作的入门级题目,与Rails(ACM/ICPC CERC 1997,UVa514)同题
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// August 27,2018
const int maxn=1000+5;
int a[maxn],b[maxn],c[maxn];
int main()
{   
    int N,M,K;
    for(scanf("%d %d %d",&M,&N,&K);K;K--)
    {
        int A=1,B=1,C=0;
        for(int i=1;i<=N;i++) {scanf("%d",&b[i]);a[i]=i;}
        while(B<=N)
        {
            if(A<=N&&a[A]==b[B]&&C<M){B++;A++;}
            else if(C&&c[C]==b[B]){C--;B++;}
            else if(C<M&&A<=N)c[++C]=a[A++];
            else break;
        }
        B>N?printf("YES\n"):printf("NO\n");
    }
    return 0;
}
