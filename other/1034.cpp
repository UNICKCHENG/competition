#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstring>
#define N 5010
using namespace std;
// zhicheng
// January,26,2019
int f[N];
int main()
{
    // freopen("1.in","r",stdin);
    string a,b;
    while(cin>>a>>b)
    {
        int ans=0;
        memset(f,0,sizeof(f));
        for(int i=0;i<a.length();i++)
        {
            int s=0;
            for(int j=0;j<b.length();j++)
            {
                if(a[i]==b[j])f[j]=max(f[j],s+1);
                else if(a[i]>b[j])s=max(s,f[j]);
                ans=max(ans,f[j]);
            }
        }
        int lena=a.length(),lenb=b.length(),len=ans;
        len?printf("%d %d\n",lena-len,lenb-len):printf("ERROR\n");
    }
    return 0;
}