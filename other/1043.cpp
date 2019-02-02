#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
// zhicheng
// February,2,2019
const int maxn=1e6;
int primes[11111111];
bool vis[11111111];
int num=0;
void per_prime()
{// 先筛取1000000以内的所有素数
    memset(vis,true,sizeof(vis));
    for(int i=2;i<=maxn;++i)
    {
        if(vis[i]) primes[++num]=i;
        for(int j=1;j<=num;j++)
        {
            if(i*primes[j]>maxn) break;
            vis[i*primes[j]]=false;
            if(i%primes[j]==0) break;
        }
    }
}

int main()
{
    // freopen("1.in","r",stdin);
    per_prime();
    int t; scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,m,ans=0;
        scanf("%d %d",&n,&m);
        for(int i=n;i<=m;i++)
            if(vis[i]) ans++;
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}