/**
 * title: 1149 Dangerous Goods Packaging(25)
 * links: https://pintia.cn/problem-sets/994805342720868352/problems/1038429908921778176
 * 题目大意: 已知一些产品不能在同一个序列中出现，现在给定m组序列，判断每组序列中的产品中是否存在不可以共存的，如果有，打印“No”
 * 解题思路: 映射。暴力求解即可。同年乙级中原题，不再叙述。
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
// zhicheng
// January,16,2019
vector<int> ans[10010];
map<int,int> sub;
map<int,bool> vis;
int main()
{
    // freopen("1.in","r",stdin);
    int n,m,t1,t2,k,cnt=1;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&t1,&t2);
        if(sub[t1]==0) sub[t1]=cnt++;
        if(sub[t2]==0) sub[t2]=cnt++;
        ans[sub[t1]].push_back(t2);
        ans[sub[t2]].push_back(t1);
    }
    for(int i=0;i<m;i++)
    {
        bool flg=true;
        vis.clear();
        for(scanf("%d",&k);k;k--)
        {
            scanf("%d",&t1);
            if(flg==false||vis[t1]==true){flg=false;continue;}
            for(int j=0,len=ans[sub[t1]].size();j<len;j++)
            {
                vis[ans[sub[t1]][j]]=true;
            }
        }
        flg==true? printf("Yes\n"):printf("No\n");
    }
    return 0;
}