/**
 * 1008 Elevator (20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.24,2018
const int maxn=100+5;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		long long sum=0;
		int tmp1=0,tmp2;
		while(n--)
		{
			scanf("%d",&tmp2);
			if(tmp2>tmp1)sum+=(tmp2-tmp1)*6;
			else sum+=(tmp1-tmp2)*4;
			tmp1=tmp2;
			sum+=5;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
