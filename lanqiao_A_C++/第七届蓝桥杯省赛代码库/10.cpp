/**
 * 最大比例
 * 分数的最大公约数
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

void huajian(ll& a,ll& b)
{// 化简分数
    ll g=gcd(a,b);
    a/=g;
    b/=g;
}
void cmp(ll& a1,ll& b1,ll& a2,ll& b2)
{// 化简两个分数，并且保证第一个分数大于第二个分数
    huajian(a1,b1);
    huajian(a2,b2);
    if(a1*b2>=a2*b1) return;
    ll ta=a1,tb=b1;
    a1=a2;b1=b2;
    a2=ta;b2=tb;
}

void fenShuGcd(ll& a1,ll& b1,ll a2,ll b2)
{
    cmp(a1,b1,a2,b2);
    while(a2!=1||b2!=1)
    {
        // cout<<a1<<"/"<<b1<<" "<<a2<<"/"<<b2<<endl;
        a1=a1*b2;
        b1=b1*a2;
        cmp(a1,b1,a2,b2);
    }
}

int main()
{
    int n;
    ll minn=1000000000100;
    ll a[105],fenzi,fenmu;
    scanf("%d",&n);
    for(int i=0;i<n;++i) 
    {
        scanf("%lld",&a[i]);
        if(minn>a[i]) minn=a[i];
    }
    if(n==1) printf("0\n");
    else
    {
        fenzi=a[0],fenmu=minn;
        huajian(fenzi,fenmu);
        for(int i=1;i<n;++i)
        {
            if(a[i]==minn) continue;
            fenShuGcd(fenzi,fenmu,a[i],minn);//两个分数对的最大公约数
        }  
    }
    cout<<fenzi<<"/"<<fenmu<<endl;
    return 0;
}