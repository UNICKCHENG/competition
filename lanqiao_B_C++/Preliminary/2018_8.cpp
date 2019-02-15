/**
 * 乘积最大
 * 算法设计：模拟
 * 先按绝对值从大到小排序，再把每种情形都列出来，用if模拟出每种情况，大致如下
 *  1. n=k。直接求前k个数的乘积
 *  2. 全部是非负数。直接求前k个数的乘积
 *  3. 全部都是非正数。k是偶数，则求前k个数的乘积，如果k是奇数，判断是否有0存在，没有的话，则求倒数k个数
 *  4. 有正有负。若前k个数有奇数个负数，则从后面选一个大正数跟前面的小负数做交换，或者从后面选一个大负数跟前面的小正数做交换，二者取结果大的，
 *     不过需要注意后排是否还有多余数可选择
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
// zhicheng
// February,16,2019
typedef long long ll;
const int maxn=100010;
ll mod=1000000009;
int a[maxn];
bool ze=false,ne=false,ge=false;

bool cmp(int a,int b){return abs(a)>abs(b);}// 按绝对值大小排序

ll slove(int n,int k)
{
    ll ans=1;
    if(n==k)
    {
        for(int i=0;i<k;++i)
        {
            ans=(ans*a[i])%mod;
        }
    }
    else if(!ne)
    {// 全是非负数
        for(int i=0;i<k;i++)
        {
            ans=(ans*a[i])%mod;
        }
    }
    else if(!ge)
    {// 全是非正数
        if(k&1)
        {
            if(ze) ans=0;
            else
            {
                for(int i=n-1;i>=n-k;i--)
                {
                    ans=(ans*a[i])%mod;
                }
            }
        }
        else
        {
            for(int i=0;i<k;i++)
            {
                ans=(ans*a[i])%mod;
            }
        }
    }
    else
    {
        int nenum=0;
        for(int i=0;i<k;i++) {if(a[i]<0) nenum++;}
        if(nenum%2!=0)
        {// 奇数个负数
            int pos,tenenum=0,tene,tege;
            for(pos=0;pos<k;pos++)
            {
                if(a[pos]>0) tege=a[pos];
                if(a[pos]<0) tenenum++;
                if(tenenum==nenum){continue;tene=a[pos];}
                ans=(ans*a[pos])%mod;
            }
            ll te1,te2;bool fi=false,ec=false;
            for(;pos<n;pos++)
            {
                if(fi&ec) break;
                if(a[pos]>0&&!fi) {te1=a[pos];fi=true;}
                if(a[pos]<0&&!ec) {te2=a[pos];ec=true;}
            }
            ans/=tege;
            if(fi&ec)
            {// 后排还有负数和正数
                te1=(te1*tege)%mod;te2=(tene*te2)%mod;
                if(te1<te2) ans=(ans*te2)%mod;
                else ans=(ans*te1)%mod;
            }
            else if(!ec && fi)
            {// 后排没有负数
                te1=(te1*tege)%mod;
                ans=(ans*te1)%mod;
            }
            else if(!fi && ec)
            {// 后排没有正数
                te2=(tene*te2)%mod;
                ans=(ans*te2)%mod;
            }
            else
            {// 后排只剩0
                ans=0;
            }
            
        }
        else
        {// 偶数个负数
            for(int i=0;i<k;i++)
            {
                ans=(ans*a[i])%mod;
            }
        }
        
    }
    return ans;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>0) ge=true;
        else if(a[i]<0) ne=true;
        else ze=true;
    }
    sort(a,a+n,cmp);
    printf("%lld\n",slove(n,k));
    return 0;
}