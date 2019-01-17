/**
 * title: 1151 LCA in a Binary Tree(30)
 * links: https://pintia.cn/problem-sets/994805342720868352/problems/1038430130011897856
 * 题目大意: 已知一棵树的先序和中序，现在给定两个节点，如果这两个节点都属于这颗树，那么求出该两个节点的最近公共祖先
 * 解题思路: 树的最近公共祖先。虽然考察点很简单，但是数据卡的很严，第一次卡在了空间上，第二次卡在了时间上
 *          主要采用中序序列进行参照。中序序列可以简单理解为左根右，然后不断地逼近两个节点即可，即一个节点为左，一个节点为右，
 *          那么根即为他们的最近公共祖先
*/
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
// zhicheng
// January,17,2018
vector<int> in_order,per_order;
map<int,int> pos;

inline void slove(int u,int v,int& x,int l1,int r1,int l2,int r2)
{
    if(l1>r1) return;
    int p=pos[per_order[l2]],inu=pos[u],inv=pos[v];// 根节点，节点值为u,节点值为分别在中序排序中的位置
    if(inu<p&&inv<p) slove(u,v,x,l1,p-1,l2+1,l2+p-l1);// 表示u和v在左子树中
    else if(inu>p&&inv>p) slove(u,v,x,p+1,r1,l2+p-l1+1,r2);// 表示u和v在右子树中
    else x=per_order[l2];
}
int main()
{
    // freopen("1.in","r",stdin);
    int n,m;scanf("%d %d",&m,&n);
    // 读取数据
    in_order.resize(n+1);per_order.resize(n+1);
    for(int i=1;i<=n;i++){scanf("%d",&in_order[i]);pos[in_order[i]]=i;}
    for(int i=1;i<=n;i++) scanf("%d",&per_order[i]);
    // 主要操作
    for(int i=0;i<m;i++)
    {
        int u,v,x;
        scanf("%d %d",&u,&v);
        if(pos[u]==0&&pos[v]==0) {printf("ERROR: %d and %d are not found.\n",u,v);continue;}// u和v都不是这个棵树上的结点
        else if(pos[u]==0||pos[v]==0) {printf("ERROR: %d is not found.\n",pos[u]==0?u:v);continue;}// u或v不是这个课树上的节点
        // u和v都是这颗树上的节点
        slove(u,v,x,1,n,1,n);
        if(x==v) printf("%d is an ancestor of %d.\n",v,u);// u为v的子节点
        else if(x==u) printf("%d is an ancestor of %d.\n",u,v);// v为u的子节点
        else printf("LCA of %d and %d is %d.\n",u,v,x);// 发现x，且x!=u和x!=v，则x为他们的公共祖先节点
    }
    return 0;
}