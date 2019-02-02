#include<cstdio>
#include<iostream>
using namespace std;
typedef unsigned long long ull;
typedef unsigned int ui;
ui n;
// zhicheng
// February,2,2019
ull poww(ull a,ull b)
{
    ull ans=1;
    while(b>0)
    {
        if(b&1) ans*=a;
        b>>=1;
        a*=a;
    }
    return ans;
}
int main()
{
    bool flg=true;
    int i;
    scanf("%u",&n);
    for(i=1;flg;i++)
    {
        ull ans=poww(i,i);
        if(ans>n) break;
    }
    printf("%d\n",i-1);
    return 0;
}