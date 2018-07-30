/**
 * 1013 Battle Over Cities (25)
 * PTA:https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840
 * https://www.nowcoder.com/pat/1/problem/3991
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
//zhicheng
//Jul.30,2018
int v[1010][1010];
bool visit[1010];

void dfs(int node,int n)
{
    visit[node]=true;
    for(int i=1;i<=n;i++) if(visit[i]==false&&v[node][i]==1) dfs(i,n);
}
int main()
{
    int n,m,k,a,b;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++) {scanf("%d %d",&a,&b);v[a][b]=v[b][a]=1;}
    for(int i=0;i<k;i++)
    {
        int cnt=0;
        fill(visit,visit+1010,false);
        scanf("%d",&a);
        visit[a]=true;
        for(int j=1;j<=n;j++) if(visit[j]==false){dfs(j,n);cnt++;}
        printf("%d\n",cnt?cnt-1:cnt);
    }
    return 0;
}
