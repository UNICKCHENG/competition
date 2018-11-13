/**
 * 1076 Forwards on Weibo(30)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805392092020736
 * 题目大意：给定N个用户，他们都用自己的粉丝，同时他们的粉丝也有自己的粉丝，这样一直下去经过L层的话，这个人间接性拥有多少粉丝呢 
 * 解题思路：图的广度优先搜索即可完成。
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// zhicheng
// November,13,2018
int n,l,k;
vector<vector<int> > a;

int slove(int id)
{
    vector<bool> vis(n+1,false);
    queue<int> q;
    int level=l,cnt=0;
    q.push(id);
    vis[id]=true;
    while(level)
    {
        for(int i=q.size();i>0;i--)
        {
            int tmp=q.front(); q.pop();
            for(int j=0;j<a[tmp].size();j++)
            {
                if(!vis[a[tmp][j]])
                {
                    vis[a[tmp][j]]=true;
                    q.push(a[tmp][j]);
                    cnt++;
                }
            }
        }
        level--;
    }
    return cnt;
}
int main()
{
    // freopen("1.in","r",stdin);
    scanf("%d %d",&n,&l);
    a.resize(n + 1);
    for(int i=1;i<=n;i++)
    {// 输入的同时构建好被关注者和关注者的对应关系
        int m;
        for(scanf("%d",&m);m;m--)
        {
            int tmp;
            scanf("%d",&tmp);
            a[tmp].push_back(i);
        }
    }
    for(scanf("%d",&k);k;k--)
    {
        int id;
        scanf("%d",&id);
        printf("%d\n",slove(id));
    }
    return 0;
}