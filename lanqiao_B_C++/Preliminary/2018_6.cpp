#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int maxn=1e5+10;
int te1[maxn];
int te2[maxn];
int dp[maxn];
int maxn=0;

int main()
{
    int n,tmp,pos;
    long long ans=0;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++) scanf("%d",&te1[i]);
    sort(te1,te1+n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&te2[i]);
        pos=binary_search(te1,0,n,te2[i]);
        dp[te2[i]]+=pos-0+1;
    }
    sort(te2,te2+n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        pos=binary_search(te2,0,n,tmp);
        ans+=dp[te2[pos]];
    }
    return 0;
}