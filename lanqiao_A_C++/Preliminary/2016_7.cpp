/**
 * 剪邮票
 * 116
 * 思路：先选取5个格子下来，在选取的时候保证1-5个各自的编号是依次增加的，这样避免一种方案被多次选取，之后，采用联通块求法进行判断是否有且仅有一个联通块
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
int b[6];
bool xuan[13];
bool vis[13];
int re=0;

void dfs(int x,int y)
{
    if(x<0||x>=3||y<0||y>=4) return;
    if(vis[a[x][y]] || !xuan[a[x][y]]) return;
    vis[a[x][y]]=true;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}
void fun(int k)
{
    if(k>5)
    {
        int ans=0;
        memset(vis,false,sizeof(vis));
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<4;++j)
            {
                if(!vis[a[i][j]] && xuan[a[i][j]]) {dfs(i,j);ans++;}
            }
        }
        if(ans==1) 
        {
            ++re;
            for(int i=1;i<=5;i++) cout<<b[i]<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i=b[k-1]+1;i<=7+k;++i)
    {// 选出5个数
        b[k]=i;
        xuan[i]=true;
        fun(k+1);
        xuan[i]=false;
    }
}
int main()
{
    memset(xuan,false,sizeof(xuan));
    b[0]=0;
    fun(1);
    cout<<re;
    return 0;
}