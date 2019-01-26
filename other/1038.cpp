#include<cstdio>
#include<iostream>
#include<sstream>
using namespace std;
typedef unsigned long long ull;
// zhicheng
// January,26,2019
const int maxn=1010;
int da[maxn];
int n;

ull gcd(ull a,ull b){return b==0?a:gcd(b,a%b);}
inline ull lcm(ull a,ull b){return a/gcd(a,b)*b;}
inline bool read()
{
    int x; n=0;
    string ss;
    if(!getline(cin,ss)) return false;
    stringstream src(ss);
    while(src>>x) da[n++]=x;
    return n>0;
}
int main()
{
    // freopen("1.in","r",stdin);
    while(read())
    {
        ull ans=da[0];
        for(int i=1;i<n;i++)
        {
            ans=lcm(ans,da[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}