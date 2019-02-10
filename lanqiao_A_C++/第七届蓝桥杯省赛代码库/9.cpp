/**
 * 密码脱落
 * 最长公共子序列
 * 思路：与其增加字符，不如转换思路，删掉一些字符，使该字符串变成回文串
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int maxn=1010;
int dp[maxn][maxn];

int LCS(string a,string b)
{// 最长公共子序列长度
    memset(dp,0,sizeof(dp));
    int lena=a.length(),lenb=b.length();
    for(int i=0;i<lena;++i)
    {
        for(int j=0;j<lenb;++j)
        {
            if(a[i]==b[j]){dp[i+1][j+1]=dp[i][j]+1;}
            else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[lena][lenb];
}
int slove(string& str)
{
    string ss=str;
    reverse(ss.begin(),ss.end());
    return str.length()-LCS(str,ss);
}

int main()
{
    string str;
    cin>>str;
    cout<<slove(str)<<endl;
    return 0;
}