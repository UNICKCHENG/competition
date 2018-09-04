/**
 * 1011 个位数统计 (15)
 * https://www.nowcoder.com/pat/6/problem/4047
 * 耗时：11min
 */
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
//zhicheng
//Jul.5,2018
int re[10];
int main()
{
	string ss;
	while(cin>>ss)
	{
		memset(re,0,sizeof(re));
		for(int i=0;i<ss.length();i++)  re[ss[i]-'0']++;
		for(int i=0;i<10;i++)
			if(re[i]) cout<<i<<":"<<re[i]<<endl;
	} 
	return 0;
}