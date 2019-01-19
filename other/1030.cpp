#include<cstdio>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

vector<int> ltree(1010),rtree(1010),per_order,in_order,ans,re;
int n,best,val,minn;

bool read(vector<int>& a)
{// 整行读入序列
    string ss;int x;
    getline(cin,ss);
    stringstream sr(ss);
    n=0;
    while(sr>>x) {a.push_back(x);n++;}
    return n;
}
int build_tree(int l1,int r1,int l2,int r2)
{// 根据先序和中序构建二叉树
    if(l1>r1) return -1;
    int node=per_order[l2],p=l1;
    while(in_order[p]!=node) p++;
    ltree[node]=build_tree(l1,p-1,l2+1,l2+p-l1);
    rtree[node]=build_tree(p+1,r1,l2+p-l1+1,r2);
    return node;
}
void dfs_tree(int node)
{// 深搜二叉树，查找满足题意的分支
    if(node==-1) return;
    ans.push_back(node);
    val+=node;
    if(ltree[node]==-1&&rtree[node]==-1)
    {
        if(val<minn){best=node;minn=val;re=ans;}// 更新权值和最小的一条路径
        else if(val==minn&&node<best){best=node;re=ans;}// 更新权值和最小且叶子节点值最小的一条路径
    }
    dfs_tree(ltree[node]);
    dfs_tree(rtree[node]);
    val-=node;
    ans.pop_back();
}
inline void print(vector<int> a)
{// 打印序列
    for(int i=0,len=a.size();i<len;i++)
    {
        if(i!=0) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}
void clear()
{
    per_order.clear();
    in_order.clear();
}
int main()
{
    // freopen("1.in","r",stdin);
    while(read(per_order))
    {
        read(in_order);// 读取数据
        // print(per_order);print(in_order);
        val=0;minn=99999999;// val 目前二叉树分支下权值和，minn满足题意的权值最小分支的权值和
        build_tree(0,n-1,0,n-1);// 根据先序和中序构建二叉树
        dfs_tree(per_order[0]);// 深搜二叉树，查找满足题意的分支
        print(re);// 打印序列
        clear();
    }
    return 0;
}