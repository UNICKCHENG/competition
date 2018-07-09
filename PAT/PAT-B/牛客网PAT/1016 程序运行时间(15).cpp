/**
 * 1016 程序运行时间(15)
 * https://www.nowcoder.com/pat/6/problem/4052
 */
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
//zhicheng
//Jul.9,2018
const int clk_tck=100;

int main()
{
	freopen("1.txt","r",stdin);
	int c1,c2;
	while(scanf("%d %d",&c1,&c2)!=EOF)
	{
		int s=round((c2-c1)/clk_tck);
		printf("%02d:%02d:%02d\n",s/60/60,s/60%60,s%60);
	}
	return 0;
}