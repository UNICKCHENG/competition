/**
 * 1023 旧键盘打字(20)
 * https://www.nowcoder.com/pat/6/problem/4059
 */
#include<cstdio>
#include<iostream>
#include<map>
#include<cctype>
using namespace std;
//zhicheng
//Jul.16,2018
map<char,bool> m;
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		bool fg=false;
		for(int i=0;i<a.length();i++) {if(a[i]=='+')fg=true;m[a[i]]=true;}
		for(int i=0;i<b.length();i++)
		{
			char tmp=toupper(b[i]);
			if(fg&&b[i]>='A'&&b[i]<='Z') continue;//上档键已坏
			if(m[tmp]) continue;
			printf("%c",b[i]);
		}
		printf("\n");
		m.clear();
	}
	return 0;
}