/**
 * 1011 World Cup Betting (20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805504927186944
 * https://www.nowcoder.com/pat/1/problem/3993
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.28,2018
char m[]={'W','T','L'};
int main()
{
	freopen("1.txt","r",stdin);
	float pro=1;
	for(int i=0;i<3;i++) 
	{
		float tmp,maxn=0;int maxn_id;
		for(int j=0;j<3;j++){scanf("%f",&tmp);if(tmp>maxn) {maxn=tmp;maxn_id=j;}}
		printf("%c ",m[maxn_id]);
		pro*=maxn;
	}
	printf("%.2f\n",(pro*0.65-1)*2);
	return 0;
}
