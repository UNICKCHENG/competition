/**
 * 1087 有多少不同的值(20)
 * https://pintia.cn/problem-sets/994805260223102976/problems/1038429191091781632
 * 解题思路:哈希映射,凡是出现过的结果将不再记录,不过也可以用set进行操作
 */
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// September,10,2018
const int maxn=10000+5;
bool ma[maxn];
int main()
{
    int n,ans=0;
    for(scanf("%d",&n);n>0;n--)
    {
        int tmp=(int)n/2+(int)n/3+(int)n/5;
        if(ma[tmp]==true) continue;
        ma[tmp]=true;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}