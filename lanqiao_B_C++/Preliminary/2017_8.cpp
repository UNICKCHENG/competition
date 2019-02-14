/**
 * 包子凑数
 * 解题思路：GCD+背包问题
 * 首先GCD判断一下，如果最大公约数不是1的话输出INF，如果是的话，看出背包问题进行处理
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
// zhicheng
const int maxn=105;
int a[maxn];
int dp[100*100+5];

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
    int n; scanf("%d",&n);
    scanf("%d",&a[0]);
    int g=a[0];
    for(int i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        g=gcd(g,a[i]);
    }
    if(g!=1) printf("INF\n");
    else
    {// 完全背包问题
        int ans=0;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j+a[i]<=100*100+5;j++)
            {
                if(dp[j]) dp[j+a[i]]=1;
            }
        }
        for(int i=0;i<=100*100+5;i++)
        {
            if(!dp[i]) ans++;
        }
        printf("%d",ans);
    }
    return 0; 
}