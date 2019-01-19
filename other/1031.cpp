#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char g[25][25];
int n,m,vis[25][25];

void solve(int x,int y)
{
    if(x<0||x>m||y<0||y>n) return;
    if(vis[x][y]>0||g[x][y]!='@') return;
    vis[x][y]=1;
    solve(x-1,y);// 向上遍历
    solve(x+1,y);// 向下遍历
    solve(x,y-1);// 向左遍历
    solve(x,y+1);// 向右遍历
}
int main()
{
    freopen("1.in","r",stdin);
    while(scanf("%d %d",&m,&n)!=EOF&&m)
    {
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<m;i++) scanf("%s",g[i]);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(g[i][j]=='@'&&vis[i][j]==0) {ans++;solve(i,j);}
        printf("%d\n",ans);
    }
    return 0;
}