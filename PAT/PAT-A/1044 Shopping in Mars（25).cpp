/**
 * 1044 Shopping in Mars（25 分）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805439202443264
 * 题目大意:给定一个正整数序列,求连续的数之和最接近一个给定的常量M的子序列区间集合
 * 解题思路:凡是遇到求连续数之和的话,一般就得用da[i]=da[i]+da[i-1]处理好这些数
 *        刚开始用子序列长度从2到n遍历一遍,结果超时了,所以想到用二分法予以解决,因为经过刚刚处理好的数,保证数组皆为从大到小排列
 *        二分法设计时候注意事项:
 *                (1)欲找满足题意的[i,j]子序列,且该子序列和为da[j]-da[i-1],得先从i-1位置开始往后遍历
 *                (2)常规二分写法,在所取值大与想要找的数值时候,high=mid-1的,而此处high取mid便可
 *                (3)一定得是所取值大于等于想要找的数值,且最接近于它才可以存储进数组
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// August 24,2018
const int maxn=100000+5;
int da[maxn]={0};
typedef struct{int i;int j;}D;D node[maxn];
int v=0,n,m;
inline void solve()
{
    int com,low,high,mid,tmp;
    for(int i=0;i<n;i++)
    {
        com=da[i]+m;
        if(com>da[n]) break;
        low=i+1;high=n;
        while(low<=high)
        {
            if(low==high) {mid=high;break;}
            mid=(low+high)/2;
            if(da[mid]<com) low=mid+1;
            else if(da[mid]>com) high=mid;// 不取high=mid-1,因为da[mid-1]不一定大于com,从而导致区间内无比com大的数
            else if(da[mid]==com) break; 
        }
        if(v==0||da[mid]==com||(da[mid]>com&&da[mid]-com<=tmp))
        {
            if(v&&da[mid]-com<tmp) v=0;
            node[v].i=i+1;node[v].j=mid;v++;
            tmp=da[mid]-com;
        }
    }
}
int main()
{
    // freopen("1.in","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&da[i]);
        da[i]+=da[i-1];
    }
    solve();
    for(int i=0;i<v;i++) printf("%d-%d\n",node[i].i,node[i].j);
    return 0;
}
