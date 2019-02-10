/**
 * 寒假作业
 * 13!，暴力的话，本地几乎转不出来，所以dfs+剪枝优化
 * 64
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[15];
int ans=0;
bool vis[15];

void dfs(int k)
{
    if(k==11)
    {
        if(a[9]%a[10]) return;
        a[11]=a[9]/a[10];
        if(!vis[a[11]]) 
        {
            ++ans;
            // for(int i=0;i<12;i++) cout<<a[i]<<" ";
            // cout<<endl;    
        }
        return;
    }
    if(k==2)
    {
        a[2]=a[0]+a[1];
        if(a[2]>13||vis[a[k]]) return;
        vis[a[k]]=true;
        dfs(k+1);
        vis[a[k]]=false;
    }
    else if(k==5)
    {
        a[5]=a[3]-a[4];
        if(a[5]<0||vis[a[k]]) return;
        vis[a[k]]=true;
        dfs(k+1);
        vis[a[k]]=false;
    }
    else if(k==8)
    {
        a[8]=a[6]*a[7];
        if(a[8]>13||vis[a[k]]) return;
        vis[a[k]]=true;
        dfs(k+1);
        vis[a[k]]=false;
    }
    else
    {
        for(int i=1;i<=13;i++)
        {
            if(vis[i]) continue;
            vis[i]=true;
            a[k]=i;
            dfs(k+1);
            vis[i]=false;
        }
    }
}
int main()
{
    memset(vis,false,sizeof(vis));
    dfs(0);
    cout<<ans<<endl;
}