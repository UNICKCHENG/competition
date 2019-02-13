/**
 * 煤球数目
 * 答案：171700
*/
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
int main()
{
    long long int ans=0;
    int n=100;
    for(int i=1;i<=n;i++)
        ans+=i*(i+1)/2;
    printf("%lld\n",ans);
    return 0;
}