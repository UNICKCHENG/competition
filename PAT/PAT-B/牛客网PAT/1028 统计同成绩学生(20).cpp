/**
 * 1028 统计同成绩学生(20)
 * https://www.nowcoder.com/pat/6/problem/4064
 */
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
//zhicheng
//Jul.20,2018
map<int,int> m;
int main()
{
	int n,k,tmp;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--){scanf("%d",&tmp);m[tmp]++;}
		scanf("%d",&k);
		while(k--){scanf("%d",&tmp);printf("%d",m[tmp]);if(k)printf(" ");}
		printf("\n");
	}
	return 0;
}