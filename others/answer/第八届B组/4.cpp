/*
标题：方格分割

6x6的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。

如图：p1.png, p2.png, p3.png 就是可行的分割法。

试计算：
包括这3种分法在内，一共有多少种不同的分割方法。
注意：旋转对称的属于同一种分割法。

请提交该整数，不要填写任何多余的内容或说明文字。

*/
//zhicheng
#include<iostream>
using namespace std;

const int n=6;
int pass[4][2]={0,1,0,-1,1,0,-1,0};
int a[n+1][n+1]={{0,0}};
int ans=0;

void def_fun(int x,int y)
{
    if(x==0||x==n||y==0||y==n) {ans++;return;}
    for(int i=0;i<4;i++)
    {
        int tx=x+pass[i][0];
        int ty=y+pass[i][1];
        if(a[tx][ty]) continue;
        a[tx][ty]=a[n-tx][n-ty]=1;
        def_fun(tx,ty);
        a[tx][ty]=a[n-tx][n-ty]=0;
    }
}
int main()
{
    a[3][3]=1;
    def_fun(3,3);
    cout<<ans/4<<endl;
    return 0;
}