/**
 * 1007 Maximum Subsequence Sum (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
 */
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
//zhicheng
//Jul.23,2018
vector<int>a;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		bool fg=false;
		int tmp,cn=0,maxn=-1,maxn_i,maxn_j;
		int b[2];
		a.push_back(0);
		for(int i=1;i<=n;i++)
		{	
			scanf("%d",&tmp);
			if(i==1)b[0]=tmp;if(i==n)b[1]=tmp;
			if(fg==false&&tmp>=0) fg=true; //if all the K numbers are negative,fg will equal to false
			if(fg==false) continue;//get rid the negative number at the beginning
			a.push_back(tmp+a[cn++]);
			for(int j=0;j<cn;j++)
			{
				if(maxn<a[cn]-a[j]){maxn=a[cn]-a[j];maxn_i=cn;maxn_j=j+1;}
			}
		}
		if(fg==false) printf("0 %d %d\n",b[0],b[1]);
		else printf("%d %d %d\n",maxn,a[maxn_j]-a[maxn_j-1],a[maxn_i]-a[maxn_i-1]);
		a.clear();
	}
	return 0;
}
