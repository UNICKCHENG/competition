/**
 * title: 1155 Heap Paths(30)
 * links: https://pintia.cn/problem-sets/994805342720868352/problems/1071785408849047552
 * 题目大意: 给定一颗完全二叉树，遍历这棵二叉树的每条路径，判断从叶子节点到根是递增还是递减，若每条路径都是满足递增/递减，则它是Max Heap/Min Heap
 * 解题思路: 二叉树深搜。对于一颗二叉树采用深搜，优先遍历右子子树，遍历每条路径即可。
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// zhicheng
// January,15,2019
int n;
vector<int> ans,a;
vector<int> flg;// 存贮树的每个分支的排序结果，-1表示杂乱，0表示递减，1表示递增
inline void slove(int node)
{
    ans.push_back(a[node]);
    if(2*node+1>=n&&2*node+2>=n)
    {
        bool f1=false,f2=false;// f1,f2分别表示从叶子节点到根为减序列和增序列
        for(int i=0,len=ans.size();i<len;i++)
        {
            if(i!=0) printf(" ");
            if(i!=0&&ans[i-1]<ans[i]) f1=true;
            else if(i!=0&&ans[i-1]>ans[i]) f2=true;
            printf("%d",ans[i]);
        }
        printf("\n");
        if(f1==true&&f2==false) flg.push_back(0);
        else if(f1==false&&f2==true) flg.push_back(1);
        else if(f1==true&&f2==true) flg.push_back(-1);
    }
    else
    {
        if(2*node+2<n) slove(2*node+2);
        if(2*node+1<n) slove(2*node+1);
    }
    ans.pop_back();
}

int main()
{
    // freopen("1.in","r",stdin);
    scanf("%d",&n);
    a.resize(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    slove(0);
    sort(flg.begin(),flg.end());
    if(flg.size()&&flg[0]==1) printf("Max Heap\n");
    else if(flg.size()&&flg[0]==0&&flg[flg.size()-1]==0) printf("Min Heap\n");
    else printf("Not Heap\n");
    flg.clear();a.clear();
    return 0;
}