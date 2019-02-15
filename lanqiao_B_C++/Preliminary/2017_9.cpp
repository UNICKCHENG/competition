/**
 * 分巧克力
 * 解题思路：二分法，O(nlogn)
 * 在区间【1，100000】内利用二分法假设切割的正方形边长为k,按着要求切割所有的巧克力，查看是否满足题意够分给K位朋友
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
// zhicheng
// February,15,2019
const int maxn=100000+10;
int w[maxn],h[maxn];

bool judge(int l,int k,int n)
{
    ll ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=(h[i]/l)*(w[i]/l);
        if(ans>=k) return true;
    }
    return false;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i) scanf("%d %d",&h[i],&w[i]);
    int l=1,r=maxn,mid;
    while(r-l>1)
    {
        mid=(l+r)>>1;
        if(judge(mid,k,n)) l=mid;
        else r=mid;
    }
    printf("%d\n",l);
}