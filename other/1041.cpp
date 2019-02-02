#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
// zhicheng
// February,2,2019
const int maxn=1e4+5;
int dp[maxn];

int main()
{
    int n,W,w,p;
    memset(dp,0,sizeof(dp));
    scanf("%d %d",&n,&W);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&w,&p);
        for(int j=W;j>=w;j--)
            dp[j]=max(dp[j],dp[j-w]+p);
    }
    printf("%d\n",dp[W]);
}