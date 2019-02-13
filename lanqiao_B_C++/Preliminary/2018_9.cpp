#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
// zhicheng
const int maxn=1005;
char gra[maxn][maxn];
int vis[maxn][maxn];
bool exist[maxn];
int n,ans=0,exi=0;

void dfs(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n) return;// 边界
    if(vis[x][y]!=0||gra[x][y]!='#') return;// 不满足要求的点和已经遍历的点
    vis[x][y]=ans;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}
int main()
{
    memset(vis,0,sizeof(vis));
    memset(exist,false,sizeof(exist));
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",gra[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(gra[i][j]=='#')
            {
                if(vis[i][j]==0){ans++;dfs(i,j);}
                if(i-1>=0&&gra[i-1][j]=='.') continue;
                if(i+1<n&&gra[i+1][j]=='.') continue;
                if(j-1>=0&&gra[i][j-1]=='.') continue;
                if(j+1<n&&gra[i][j+1]=='.') continue;
                if(exist[vis[i][j]]) continue;
                exist[vis[i][j]]=true;
                exi++;
            }
        }
    }
    printf("%d\n",ans-exi);
    return 0;
}