/**
 * 方格分割
 * 509
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

bool vis[6][6];
int map[6][6]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
bool m[37];
int a[19];
int re=0;


void dfs(int x,int y)
{// 查找联通块
    if(x<0||x>5||y<0||y>5) return;
    if(vis[x][y]||!m[map[x][y]]) return;
    vis[x][y]=true;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}
void slove(int k)
{   
    if(k>18)
    {
        memset(vis,false,sizeof(vis));
        int f=0;
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(vis[i][j]||(!m[map[i][j]])) continue; 
                f++;
                if(f>1) return;
                dfs(i,j);
            }
        }
        re++;
        return;
    }
    for(int i=a[k-1]+1;i<=18+k;i++) 
    {
        a[k]=i;
        m[a[k]]=true;// 该点已选
        if(!m[36-a[k]+1]) slove(k+1);// 且该点的对称点未被选取
        m[a[k]]=false;// 释放该点
    }
}
int main()
{
    memset(m,false,sizeof(m));
    memset(a,0,sizeof(a));
    slove(1);
    printf("%d\n",re/4);
    return 0;
}