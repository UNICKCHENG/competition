#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[10010];
int main()
{
    int n,minn,ans=0;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        minn=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[minn]) minn=j;
        }
        if(a[minn]!=a[i])
        {
            // printf("%d-%d\n",a[i],a[minn]);
            swap(a[i],a[minn]);
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}