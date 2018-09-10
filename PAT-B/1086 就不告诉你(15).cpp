/**
 * 1086 就不告诉你(15)
 * https://pintia.cn/problem-sets/994805260223102976/problems/1038429065476579328
 * 解题思路:数学问题,将两个整数的乘积倒着输出,需要注意的是开头不可为0
*/
#include<cstdio>
#include<iostream>
using namespace std;
// zhicheng
// September,10,2018
int main()
{
    int a,b,n,cnt=0;bool flg=false;
    scanf("%d %d",&a,&b); n=a*b;
    if(n==0) {printf("0\n");return 0;} // 乘积为0的特殊情况处理
    while(n)
    {
        if(flg==false&&!(n%10)) {n/=10;continue;}// 首位不得为0
        printf("%d",n%10);n/=10;flg=true;
    }
    printf("\n");
    return 0;
}