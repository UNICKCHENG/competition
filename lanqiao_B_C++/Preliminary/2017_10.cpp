/**
 * k倍区间
 * 解题思路：前缀和
 * 假设从0~i区间的序列和除以K的余数为mod1，从0~j区间的序列和除以K的余数为mod2，如果mod1=mode2,则表示i~j区间的序列和为K倍数，把这样的情况加起来为ans
 * 最后需要注意的的是，如果mod1=mod2=0,结果还得再加上这样的情况次数，因为不仅i~j区间满足，同时0~i和0~j也满足
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
// zhicheng
// February,15,2019
const int maxn=100010;
int mod[maxn];
int main()
{
    int n,k,tmp=0,x,ans=0;
    memset(mod,0,sizeof(mod));
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&x);
        tmp=(tmp+x)%k;
        ans+=mod[tmp];
        ++mod[tmp];
    }
    printf("%d\n",ans+mod[0]);
    return 0;
}