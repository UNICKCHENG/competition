/**
 * 1086 Tree Traversals Again(25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805380754817024
 * 题目大意：先给定一颗二叉树的节点数目，然后入栈和出栈，入栈顺序以先序顺序，出栈以中序顺序输出，最后要以后序输出
 * 解题思路：树的操作。根据入栈和出栈得到先序和中序，然后构建二叉树，最后以后序输出即可
 */
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
// zhicheng
// November,12,2018
const int maxn=35;
int a[maxn],per[maxn],in[maxn],ltree[maxn],rtree[maxn],root;

int build(int l1,int r1,int l2,int r2)
{
    if(l1>r1) return 0;
    int node=per[l2];
    int p=l1;
    while(node!=in[p]) p++;
    ltree[node]=build(l1,p-1,l2+1,l2+p-l1);
    rtree[node]=build(p+1,r1,l2+p-l1+1,r2);
    return node;
}
void post(int node)
{
    if(ltree[node]) post(ltree[node]);
    if(rtree[node]) post(rtree[node]);
    if(node!=root) printf("%d ",node);
}
int main()
{
    // freopen("1.in","r",stdin);
    int n;char c[4];
    int v=0,k=0,cn=0;
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
    {
        scanf("%s",c);
        if(c[1]=='u') {scanf("%d",&per[v]);a[++cn]=per[v++];}
        else in[k++]=a[cn--];
    }
    root=build(0,n-1,0,n-1);
    post(root);
    printf("%d",root);
    return 0;
}