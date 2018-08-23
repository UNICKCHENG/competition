/**
 * 1040 Longest Symmetric String (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805446102073344
 * 题目大意:给定一串字符(含空格),找出最长回文子串的长度
 * 解题思路:动态规划进行最长回文子串查找
 */ 
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
// zhicheng
// August 23,2018
const int maxn=1000+5;
string ss;
bool dp[maxn][maxn];
int main()
{
    getline(cin,ss);
    int len=ss.length(),ans=1;
    for(int i=0;i<len;i++)
    {
        dp[i][i]=true;
        if(i<len-1&&ss[i]==ss[i+1]){ans=2;dp[i][i+1]=true;}
    }
    for(int l=3;l<=len;l++)
        for(int i=0,j=l+i-1;j<len;i++,j++)
            if(ss[i]==ss[j]&&dp[i+1][j-1])
            {
                dp[i][j]=true;
                ans=l;
            }
    printf("%d\n",ans);
    return 0;
}
