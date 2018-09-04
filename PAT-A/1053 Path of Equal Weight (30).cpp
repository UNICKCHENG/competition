/**
 * 1053 Path of Equal Weight (30)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512
 * 题目大意:给定一个树,输出满足从根一直到叶子节点权值之和为S的路径
 * 解题思路:各节点的权值存放在数组w中即可,遍历时按编号对树进行遍历,因为查看某节点权值时该节点的编号便是数组w的下标
 *         首先存放各个节点的子节点,按权值的大小由左往右表示子节点(左大右小)---->这一步很重要,因为在找到满足的路径时无需再按要求排序
 *         其次深度遍历,遍历到叶子结点判断该路径下所有节点权值之和ans是否等于S,若等于则该路径满足题意,并一一输出各个节点的权值
 *         最后需要注意的是,为了节约时间可以采用分支限界,判断该节点下权值之和ans是否已超出S,若是这样,该节点下的分支将不必再遍历了
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// zhicheng
// August 27,2018
const int maxn=105;
vector<int> a[maxn];//存放各个节点的子节点
int tmp[maxn],w[maxn];// tmp存储每种路径遍历的结点,w存放各节点权值
int n,m,s,cnt=0;
long long ans=0;
bool cmp(int p,int q){return w[p]>w[q];}
void solve(int node)
{
    if(ans+w[node]>s) return;
    ans+=w[node];
    tmp[cnt++]=node;
    if(ans==s&&a[node].empty())// 叶子节点
        for(int i=0;i<cnt;i++)
            printf("%d%c",w[tmp[i]],i==cnt-1?'\n':' ');
    else if(ans<s)// 非叶子节点
        for(int i=0;i<a[node].size();i++) solve(a[node][i]);
    ans-=w[node];
    cnt--;
}

int main()
{
    // freopen("1.in","r",stdin);
    scanf("%d %d %d",&n,&m,&s);
    for(int i=0;i<n;i++) scanf("%d",&w[i]);
    for(int id,num,sub_id,i=0;i<m;i++)
    {
        scanf("%d %d",&id,&num);
        while(num--) 
        {
            scanf("%d",&sub_id);
            a[id].push_back(sub_id);
        }
        sort(a[id].begin(),a[id].end(),cmp);// 将子节点权值大的放左边,即遍历子节点时先遍历
    }
    solve(0);
    return 0;
}
