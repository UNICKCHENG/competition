#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=10010;
int vis[maxn][maxn];
int main()
{
    int n,x1,y1,x2,y2,tx,ty;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        tx=min(x1,x2);x2=x1+x2-tx;x1=tx;
        ty=min(y1,y2);y2=y1+y2-ty;y1=ty;
        for(int i=0;i<)
    }
    return 0;
}