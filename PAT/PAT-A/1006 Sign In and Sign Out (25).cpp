/**
 * 1006 Sign In and Sign Out (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.22,2018
int main()
{
	//freopen("1.txt","r",stdin);
	int n;string s[3];
	while(scanf("%d",&n)!=EOF)
	{
		string minn_id,maxn_id;
		string minn="24:00:00";
		string maxn="00:00:00";
		while(n--)
		{
			for(int i=0;i<3;i++)cin>>s[i];
			if(s[1]<=minn){minn_id=s[0];minn=s[1];}
			if(s[2]>=maxn){maxn_id=s[0];maxn=s[2];}
		}
		printf("%s %s\n",minn_id.c_str(),maxn_id.c_str());
	}
	return 0;
}
