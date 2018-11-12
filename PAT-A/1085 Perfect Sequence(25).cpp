/**
 * 1085 Perfect Sequence(25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805381845336064
 * 题目大意：从一组序列中找出一组数，该序列要 满足最大数M<=最小数m*p,这样的序列最多为多少个元素组成
 * 解题思路：让序列所有元素从小到大排序，利用二分法从第一个元素往后找即可
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// zhicheng
// November,12,2018
const int maxn=100000+5;
int a[maxn];
int main()
{ 
    // freopen("1.in","r",stdin);
    int n,p;scanf("%d %d",&n,&p);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int cur,best=0;
    for(int i=0;best<n-i;i++)
    {
        cur=upper_bound(a+i+1,a+n,(long long)a[i]*p)-a;
        best=max(best,cur-i);
    }
    printf("%d\n",best);
    return 0;
}