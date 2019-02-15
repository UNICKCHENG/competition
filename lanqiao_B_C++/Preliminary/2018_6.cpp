/**
 * 递增三元组
 * 算法设计：O(n)
 * 以集合B为基，a[i]表示集合A中不大于i的元素有a[i]个，c[i]表示集合C中不小于i的元素有c[i]个，那么集合B中某个元素为b，则该组合有a[b-1]*c[b+1]种
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
// zhicheng
// February,15,2019
const int maxn=100010;
int a[maxn],b[maxn],c[maxn];
int main()
{
    // freopen("递增三元组/10.in","r",stdin);
    int n,tmp;
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    scanf("%d",&n);
    for(int i=0;i<n;++i) 
    {
        scanf("%d",&tmp);
        ++a[tmp];
    }
    for(int i=0;i<n;++i) scanf("%d",&b[i]);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&tmp);
        ++c[tmp];
    }
    for(int i=1;i<maxn;++i) a[i]+=a[i-1];
    for(int i=maxn-1;i>0;--i) c[i]+=c[i+1];
    long long ans=0;
    for(int i=0;i<n;++i)
    {
        if(b[i]==0) continue;
        ans+=(long long)a[b[i]-1]*c[b[i]+1];
    }
    printf("%lld\n",ans);
}