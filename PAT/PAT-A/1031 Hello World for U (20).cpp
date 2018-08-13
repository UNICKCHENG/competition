/**
 * 1031 Hello World for U (20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805462535356416
 */
#include<cstdio>
#include<cstring>
//zhicheng
//August 13,2018
const int maxn=85;
char a[maxn];
int main()
{
	scanf("%s",a);
	int len=strlen(a);
	int h=(len+2)/3,w=(len+2)/3+(len+2)%3,i=0,j=len-1;
	for(int k=1;k<h;k++)
	{
		printf("%c",a[i++]);
		for(int v=1;v<=w-2;v++) printf(" ");
		printf("%c",a[j--]);
		printf("\n");
	}
	for(;i<=j;)printf("%c",a[i++]);
	printf("\n");
	return 0;
}
