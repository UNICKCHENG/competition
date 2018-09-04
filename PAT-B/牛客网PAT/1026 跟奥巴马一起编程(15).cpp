/**
 * 1026 跟奥巴马一起编程(15)
 * https://www.nowcoder.com/pat/6/problem/4062
 */
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
//zhicheng
//Jul.18,2018
inline void print(int n,char c)
{
  int line=floor(n*1.0/2+0.5);
  for(int i=1;i<=line;i++)
  {
    int column=n-2;//中间列数
    printf("%c",c);
    if(i==1||i==line) while(column--)printf("%c",c);
    else while(column--)printf(" ");
    printf("%c\n",c);
  }
}
int main()
{
	int n;char c;
	while(scanf("%d %c",&n,&c)!=EOF) print(n,c);	
}