/**
 * 1047 Student List for Course（25 分）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805433955368960
 * 题目大意:给出N位同学选课情况,输出每门课下选课同学姓名(按字母从小到大)
 * 解题思路:不再赘述,可比较查看[PAT-A-1039]]https://github.com/UNICKCHENG/competition/blob/master/PAT/PAT-A/1039%20Course%20List%20for%20Student%20(25).cpp
 *         此题对时间限制做了极大的放宽,就未牺牲空间以节约时间了
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// zhicheng
// August 26,2018
int const maxn=2500+5;
vector<string> a[maxn]; 

bool comp(string p,string q){return p<q;}
int main()
{
    // freopen("1.in","r",stdin);
    int n,k,c,co;string name;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        cin>>name;
        for(scanf("%d",&c);c;c--)
        {
            scanf("%d",&co);
            a[co].push_back(name);
        }
    }
    for(int i=1;i<=k;i++)
    {
        int mem=a[i].size();
        printf("%d %d\n",i,mem);
        sort(a[i].begin(),a[i].end(),comp);
        for(int j=0;j<mem;j++)
            printf("%s\n",a[i][j].c_str());
    }
    return 0;
}
