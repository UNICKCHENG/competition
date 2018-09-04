/*
 * 1027 Colors in Mars (20)（20 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805470349344768
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//August 10,2018
int main()
{
	char c[14]={"0123456789ABC"};
	printf("#");
	for(int i=0;i<3;i++)
	{
		int rgb;
		scanf("%d",&rgb);
		printf("%c%c",c[rgb/13],c[rgb%13]);
	}
	printf("\n");
	return 0;
}
