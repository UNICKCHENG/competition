/**
 * 1069 The Black Hole of Numbers(20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805400954585088
 * 题目大意 : 给定一个不超过4位数的正整数,将这个数从大到小排序减去从小到大排序后的结果是否会等于6174这个定值
 * 解题思路: 简单的数学题.需要用到STL的排序函数sort
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// zhicheng
// Octcber,8,2018
int main()
{
    char a[4];int num;
    scanf("%d",&num);
    do
    {
        for(int i=0;i<4;i++){a[i]=num%10+'0';num/=10;}
        int num1=0,num2=0;
        sort(a,a+4,less<int>());
        for(int i=0;i<4;i++) num1=num1*10+(a[i]-'0');
        sort(a,a+4,greater<int>());
        for(int i=0;i<4;i++) num2=num2*10+(a[i]-'0');
        num=num2-num1;
        printf("%04d - %04d = %04d\n",num2,num1,num);
    }while(num&&num!=6174);
    return 0;
}