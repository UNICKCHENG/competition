/**
 * 1002	A+B for Polynomials (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.6,2018
int main()
{
	freopen("1.txt","r",stdin);
	float c[1001]={0};
	int m,te1,count=0;
	float te2;
	for(int i=0;i<2;i++)
	{
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			cin>>te1>>te2;
			c[te1]+=te2;
		}
	}
	for(int i=1000;i>=0;i--) if(c[i]) count++;
	cout<<count;
	for(int i=1000;i>=0;i--)  if(c[i]) printf(" %d %.1f",i,c[i]);
	cout<<endl;
	return 0;
}