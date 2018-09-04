/**
 * 1041 Be Unique (20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805444361437184
 * 题目大意:输入一组数,按其顺序找到第一个没有重复的数字
 * 解题思路:哈希散列
 */ 
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// August 23,2018
const int maxn=100000+5;
int m[maxn]={0},a[maxn];
int main()
{
    int n,_;
    for(scanf("%d",&n),_=n;_;_--) {scanf("%d",&a[_]);m[a[_]]++;}
    for(int i=n;i>0;i--)if(m[a[i]]==1) {printf("%d\n",a[i]);return 0;}
    printf("None\n");
    return 0;
}
