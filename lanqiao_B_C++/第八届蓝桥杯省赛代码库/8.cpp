/**
 * 包子凑数
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn=105;
int a[maxn];
queue<int> q;

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
    int n,g=1,minn;
    scanf("%d",&n);
    scanf("%d",&a[0]);minn=g=a[0];
    for(int i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        g=gcd(g,a[i]);
        if(minn>a[i]) minn=a[i];
    }
    if(g!=1) printf("INF\n");
    else
    {
        int ans=0;
        for(int i=1;i<minn;i++) {ans++;q.push(i);}
        while(!q.empty())
        {
            bool flg=true;
            int tmp=q.front()+minn;q.pop();
            for(int i=0;i<n;i++)
            {
                if(tmp%a[i]==0){flg=false;break;}
            }
            if(flg==false) continue;
            q.push(tmp);
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0; 
}