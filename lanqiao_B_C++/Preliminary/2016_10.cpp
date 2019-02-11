#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;
const int maxn=105;
ll a[maxn];

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
void swap(ll& a,ll& b){ll tmp=a;a=b;b=tmp;}
void fun(ll a,ll b,ll &ta,ll &tb)
{
    ll a1=a,b1=1,a2=b,b2=1,g;
    while(a1*b2-a2*b1!=0)
    {
        g=gcd(a1*b2,a2*b1);
        ta=a1*b2/g;tb=a2*b1/g;
        if(ta*b2-a2*tb>0) {a1=ta;a2=tb;}
        else{a1=a2;b1=b2;a2=ta;b2=tb;}
    }
    ta=a1;tb=b1;
}
int main()
{
    ll ta,tb,am,bm=0,minn=-1;
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        scanf("%lld",&a[i]);
        if(minn==-1||a[minn]>a[i]) minn=i;
    }
    swap(a[minn],a[0]);
    for(int i=1;i<n-1;i++)
    {
        if(a[i]>a[i+1]) fun(a[i],a[i+1],ta,tb);
        else fun(a[i+1],a[i],ta,tb);
        if(bm==0||am*tb-ta*bm>0) {am=ta,bm=tb;}
    }
    printf("%lld/%lld\n",am,bm);
    return 0;
}
