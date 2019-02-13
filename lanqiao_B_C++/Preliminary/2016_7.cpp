/**
 * 剪邮票
 * 从这12个格子中抽取5个格子出来（将所有组合罗列出），对每种情况进行判断，利用dfs查看是否只有一个联通块，如果是则满足要求
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
// zhicheng
// January,30,2019
bool m[13];
bool vis[3][4];
int map[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};

void dfs(int x,int y)
{// 利用dfs查看3*4的格子，是否只有一个联通块
    if(x<0||x>2||y<0||y>3) return;// 边界
    if(vis[x][y]||!m[map[x][y]]) return ;// 这个点走过了，或者这个点不是计算点
    vis[x][y]=true;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}
int main()
{
    int ans=0;
    for(int a=1;a<=8;a++)
        for(int b=a+1;b<=9;b++)
            for(int c=b+1;c<=10;c++)
                for(int d=c+1;d<=11;d++)
                    for(int e=d+1;e<=12;e++)
                    {
                        int f=0;// 表示有几个联通块
                        memset(vis,false,sizeof(vis));
                        memset(m,false,sizeof(m));
                        m[a]=m[b]=m[c]=m[d]=m[e]=true;
                        for(int i=0;i<3;i++)
                            for(int j=0;j<4;j++)
                            {
                                if(m[map[i][j]]&&!vis[i][j])
                                {
                                    dfs(i,j);
                                    f++;
                                }
                            }
                        if(f==1) 
                        {
                            ans++;// 表示该种情况下只有一个连通图     
                            // printf("#%d : %d %d %d %d %d\n",ans,a,b,c,d,e);
                        }
                    }
    printf("%d\n",ans);
}