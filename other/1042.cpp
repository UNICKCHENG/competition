#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
// zhicheng
// February,2,2019
bool vis[6][6];// 遍历图
bool num[37];// 记录了选取了哪些编号
int map[6][6]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};

void dfs(int x,int y)
{
    if(x<0||x>5||y<0||y>5) return;//边界
    if(vis[x][y]||!num[map[x][y]]) return;
    vis[x][y]=true;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}
int main()
{
    // freopen("1.in","r",stdin);
    int n,tmp;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int ans=0;// 表示该情况下存在的联通块个数
        memset(num,0,sizeof(num));
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            num[tmp]=true;
        }
        for(int i=0;i<6;i++)
            for(int j=0;j<6;j++)
                if(num[map[i][j]]&&!vis[i][j]){ans++;dfs(i,j);}
        ans>1?printf("NO\n"):printf("YES\n");
    }
    return 0;
}