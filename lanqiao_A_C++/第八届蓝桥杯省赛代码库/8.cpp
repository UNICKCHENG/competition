#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=105;
bool vis[maxn*maxn];

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int solve(int* a,int n)
{
    int ans=0;
    
    return ans;
}
int main()
{
    int a[maxn],n;
    scanf("%d\n",&n,&a[0]);
    int g=a[0];
    for(int i=1;i<n;i++) 
    {
        scanf("%d",&a[i]);
        g=gcd(g,a[i]);
    }
    if(g!=1) printf("INF\n");
    else printf("%d\n",solve(a,n));
    return 0;
}