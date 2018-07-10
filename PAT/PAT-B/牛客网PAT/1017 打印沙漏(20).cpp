/**
 * 1017 打印沙漏(20)
 * https://www.nowcoder.com/pat/6/problem/4053
 */
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
//zhicheng
//Jul.10,2018
void print(int n,char a)
{
	for(int i=0;i<2*n+1;i++)
	{
		for(int j=0;j<n-fabs(n-i);j++)printf(" ");
		for(int j=0;j<2*fabs(n-i)+1;j++)printf("%c",a);
		printf("\n");
	}
}
int main()
{
	int n;char a;
	while(scanf("%d %c",&n,&a)!=EOF)
	{
		int te=n-1,count=0;
		for(int i=3;2*i<=te;i+=2){te=te-2*i;count++;}
		print(count,a);
		printf("%d\n",te);
	}
	return 0;
}