/**
 * 1083 是否存在相等的差(20)
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805260780945408
 * 解题思路:哈希映射.因为时间的限制,所以最好在输入的时候处理好每张牌对应的差值
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// September,4,2018
int m[10000]={0};
int main()
{
    int n,num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num);
        m[num-i<0?i-num:num-i]++;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(m[i]==0||m[i]==1) continue;
        printf("%d %d\n",i,m[i]);
    }
    return 0;
}