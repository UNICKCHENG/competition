#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
// zhicheng
// January,26,2019
int main()
{
    // freopen("1.in","r",stdin);
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        ll tmp;
        ll max1=0,max2=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&tmp);
            max1+=tmp;
            if(max1<0) max1=0;
            if(max1>max2){max2=max1;}
        }
        printf("Case#%d:%lld\n",i,max2);
    }
    return 0;
}