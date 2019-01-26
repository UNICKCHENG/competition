#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
// zhicheng
// January,26,2019
const int maxn=1010;
int dp[maxn][maxn];

int main()
{
    // freopen("1.in","r",stdin);
    string a,b;
    while(cin>>a>>b)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;a[i]!='\0';i++)
        {
            for(int j=0;b[j]!='\0';j++)
            {
                if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
                else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        int lena=a.length(),lenb=b.length(),len=dp[a.length()][b.length()];
        len?printf("%d %d\n",lena-len,lenb-len):printf("ERROR\n");
    }
    return 0;
}