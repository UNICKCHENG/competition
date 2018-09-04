/**
 * 1037 Magic Coupon (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805451374313472
 * 题目大意:两组序列中的元素,一一对应相乘,乘积之和最大为多少
 * 解题思路:给两组序列排序,最大的正数之间相乘,最小的负数之间相称,其乘积之和必为最大
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// zhicheng
// August 19,2018
vector<int> a;
vector<int> b;
int main()
{
    int np,nc,tmp,_;long long int sum=0;
    for(scanf("%d",&nc),_=nc;_;_--){scanf("%d",&tmp);a.push_back(tmp);}
    for(scanf("%d",&np),_=np;_;_--){scanf("%d",&tmp);b.push_back(tmp);}
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int p=0,c=0;
    while(p<np&&c<nc&&a[c]<0&&b[p]<0){sum+=a[c]*b[p];p++;c++;}// 最小的负数之间相称
    p=np-1;c=nc-1;
    while(p>=0&&c>=0&&a[c]>0&&b[p]>0){sum+=a[c]*b[p];p--;c--;}// 最大的正数之间相乘
    printf("%lld\n",sum);
    a.clear();b.clear();
    return 0;
}
