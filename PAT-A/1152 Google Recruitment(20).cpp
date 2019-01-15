/**
 * title: 1152 Google Recruitment(20)
 * links:https://pintia.cn/problem-sets/994805342720868352/problems/1071785055080476672
 * 题目大意：从长度为L的整数中自左向右进行寻找，需要找到长度为L的一个整数，并且这个整数是素数，如果存在这样的数就把它输出，否则输出404
 * 解题思路：素数判定。
*/
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
// zhicheng
// January,10,2019
bool is_Prime(long long int n)
{// 判断其是否为素数
    if(n<2) return false;
    for(int i=2;i<=n/i;i++) if(n%i==0) return false;
    return true;
}
int numlen(long long int n)
{// 求一个整数的长度
    int len=0;
    while(n)
    {
        len++;
        n/=10;
    }
    return len;
}
int main()
{
    int l,k,len=0;;
    long long int tmp=0;
    bool flg=false; // 标记是否存在这样的素数
    char c;
    scanf("%d %d",&l,&k);getchar();
    long long int mod=pow(10,k);// 用于取模，保证截取长度为K
    while(len<l)
    {
        c=getchar();++len;
        if(flg==true) continue;
        tmp=tmp*10+(c-'0');
        // printf("+ %d\n",tmp);
        if(len>=k)
        {
            tmp%=mod;
            // printf("* %d\n",tmp);
            if(is_Prime(tmp)) flg=true;
        }
    }
    if(flg==true)
    {// 按格式输出
        len=numlen(tmp);
        while(len<k){printf("0");len++;}
        printf("%lld\n",tmp);
    }
    else printf("404\n");
    return 0;
}