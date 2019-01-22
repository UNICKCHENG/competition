/**
 * title: 1147 Heaps(30)
 * links: https://pintia.cn/problem-sets/994805342720868352/problems/994805342821531648
 * 题目大意：判断一颗完全二叉树每条分支从叶子结点到根的权值是属于从小到大，还是从大到小，抑或是乱序，同时将这棵树按照后序遍历打印各个结点的值
 * 解题思路：树的dfs+后序。利用dfs遍历树的每条分支，判断每条分支属于乱序还是有序，如果有序的话，是不是每条分支都遵循一样的顺序。
 *          对于后序遍历，直接递归遍历即可。
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// zhicheng
// January,22,2019
vector<int> a;
vector<int> ans;
vector<int> flg;
int m,n;
void slove(int x)
{// dfs搜索，遍历树的每条分支
    ans.push_back(a[x]);
    if(2*x>n)
    {
        int fg=0,f;
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]>ans[i-1]) f=-1;// 从叶子节点到根为递减
            else if(ans[i]<ans[i-1]) f=1;// 从叶子节点到根递增
            else f=fg;
            // 局部趋势与大趋势比较
            if(fg==0) fg=f;
            else if(f!=fg) {fg=0;break;}
        }
        flg.push_back(fg);// 存入该路径的整体趋势
    }
    else
    {
        if(2*x<=n) slove(2*x);
        if(2*x+1<=n) slove(2*x+1);
    }
    ans.pop_back();
}
inline void post_print(int x,bool& first)
{// 树的后序遍历
    if(x>n) return;
    post_print(2*x,first);
    post_print(2*x+1,first);
    if(first==true) printf(" ");
    else first=true;// 保证输出格式
    printf("%d",a[x]);
}
int main()
{
    // freopen("1.in","r",stdin);
    scanf("%d %d",&m,&n);
    a.resize(n+1);
    while(m--)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        slove(1);
        sort(flg.begin(),flg.end());
        if(flg[0]==1) printf("Max Heap\n");
        else if(flg[flg.size()-1]==-1) printf("Min Heap\n");
        else printf("Not Heap\n");
        bool fi=false;
        post_print(1,fi);
        printf("\n");
        a.clear();
        flg.clear();
    }
    return 0;
}