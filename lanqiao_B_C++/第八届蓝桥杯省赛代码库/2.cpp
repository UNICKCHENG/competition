/**
 * 等差素数列
 * 210
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=10000;
int primes[11111111];
bool vis[11111111];
int num=0;
void per_prime()
{
    memset(vis,true,sizeof(vis));
    for(int i=2;i<=maxn;++i)
    {
        if(vis[i]) primes[++num]=i;
        for(int j=1;j<=num;j++)
        {
            if(i*primes[j]>maxn) break;
            vis[i*primes[j]]=false;
            if(i%primes[j]==0) break;
        }
    }
}

int main()
{
    per_prime();
    // for(int i=1;i<=num;i++) printf("%d ",primes[i]);
    for(int d=2;d<maxn;d++)
    {
        for(int k=1;k<=num;k++)
        {
            printf("#%d\n",d);
            bool flg=true;
            int tmp=primes[k];
            if(tmp+9*d>maxn) break;
            for(int i=0;i<10;i++)
            {
                if(!vis[tmp]) {flg=false;break;}
                tmp+=d;
            }
            if(flg){printf("%d\n",d);return 0;}
        }
    }
    return 0;
}