/**
 * k倍区间
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=100010;
int co[maxn];
int main()
{
    freopen("1.in","r",stdin);
    int n,k,tmp,pos=0,ans=0;
    memset(co,0,sizeof(co));
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        pos=(pos+tmp)%k;
        ans+=co[pos];
        co[pos]++;
    }
    printf("%d\n",ans+co[0]);
    return 0;
}