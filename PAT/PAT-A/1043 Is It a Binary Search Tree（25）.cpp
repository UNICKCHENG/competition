/**
 * 1043 Is It a Binary Search Tree（25 分）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805440976633856
 * 题目大意:给定一组树的先序遍历,如果该树为二叉搜索树或者镜像二叉搜索树,则输出该树的后序遍历,否则输出NO
 * 测试数据:
      INPUT:
          3
          10 8 11
          7
          8 6 5 7 10 8 11
          7
          8 6 8 5 10 9 11
          4
          8 10 8 11
      OUTPUT:
          YES
          8 11 10
          YES
          5 7 6 8 11 10 8
          NO
          YES
          8 11 10 8
 */


/**
 * 解题思路:对于二叉搜索树或者镜像二叉搜索树,无非是结点的权值决定位置在左还是右,并不影响接替关键
 *         1.将先序结果转后序存放至数组中,在此过程中同时判断是否为二叉搜索树或者镜像二叉搜索树,是则返回true,否则返回fasle
 *         2.对于是二叉搜索树还是镜像二叉搜索树,可用pre_order[0]和pre_order[1]简单判断下
 *                (1)pre_order[0]>pre_order[1],则此有可能为二叉搜索树,反之,则可能为镜像二叉搜索树
 *                (2)对于(1)只能大概估计,因为有可能出现像[8 10 8 11]这样一组数,或者[8 9 10 12]这样更特殊的情况
 *                (3)如若只考虑到(1),(2)未曾想到,题目也能AC,因为PAT官网的测试数据并未出现这样的特殊情况
 *         3.考虑到第2点中(2)这样的特殊例子,所以仍然只能采用先按二叉搜索树进行判断,如若false,则再按镜像二叉搜索树}
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// August 24,2018
const int maxn=1000+5;
int pre_order[maxn],post_order[maxn];

bool solve(int l,int r,bool fg,int& k)
{
    if(l>r) return true;
    int node=pre_order[l],p=l+1,q;
    while((fg==true&&p<=r&&node>pre_order[p])||(fg==false&&p<=r&&node<=pre_order[p])) p++;q=p;
    while((fg&&q<=r&&node<=pre_order[q])||(fg==false&&q<=r&&node>pre_order[q])) q++;
    bool fl=solve(l+1,p-1,fg,k);
    bool fr=solve(p,r,fg,k);
    post_order[k++]=node;// 将后序结果存放至数组中
    return fl&&fr&&q>r;// 返回该节点是否满足二叉搜索树或者镜像二叉搜索树的特征
}

int main()
{
    // freopen("1.in","r",stdin);
    int n,v=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&pre_order[i]);
    bool fg=pre_order[0]>pre_order[1]?true:false;//简单判断是二叉搜索树还是镜像二叉搜索树
    bool re=solve(0,n-1,fg,v);
    if(!re) {v=0;re=solve(0,n-1,!fg,v);}
    if(!re) printf("NO\n");
    else{
        printf("YES\n");
        for(int i=0;i<v;i++) {
            if(i) printf(" ");
            printf("%d",post_order[i]);
        }
        printf("\n");
    }
    return 0;
}
