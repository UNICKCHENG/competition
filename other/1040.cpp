#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
// zhicheng
// February,2,2019
const int maxn=1e9+5;
const int mod=1000000007;
char str[maxn];
int main()
{
    // freopen("1.in","r",stdin);
    int a=0,c=0,m=0;
    scanf("%s",str);
    for(int i=0,len=strlen(str);i<len;i++)
    {
        switch(str[i])
        {
            case 'A': a=(a+1)%mod;break;
            case 'C': c=(c+a)%mod;break;
            case 'M': m=(m+c)%mod;break;
            default:break;
        }
    }
    printf("%d\n",m);
    return 0;
}