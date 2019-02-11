/**
 * 方格分割
 * 509
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>
using namespace std;

bool vis[7][7];
int ans=0;

void dfs(int x,int y)
{
    if(x==0||x==6||y==0||y==6)
    {
        ans++;
        return;
    }
    if(vis[x][y]) return;//已经走过的点
    vis[x][y]=vis[6-x][6-y]=true;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
    vis[x][y]=vis[6-x][6-y]=false;
}
int main()
{
    memset(vis,false,sizeof(vis));
    dfs(3,3);
    cout<<ans/4<<endl;
    return 0;
}