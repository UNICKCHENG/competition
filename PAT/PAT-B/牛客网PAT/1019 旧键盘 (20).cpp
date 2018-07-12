/**
 * 1019 旧键盘 (20)
 * https://www.nowcoder.com/pat/6/problem/4055
 */
#include<cstdio>
#include<iostream>
#include<map>
#include<cctype>
using namespace std;
//zhicheng
//Jul.11,2018
map<char,bool> m;

int main()
{
	freopen("1.txt","r",stdin); 	
	string s1,s2;
	while(cin>>s1>>s2)
	{
		for(int i=0;i<s2.length();i++) {char c=toupper(s2[i]);if(m[c]==false) m[c]=true;}
		for(int i=0;i<s1.length();i++) 
		{
			char c=toupper(s1[i]);
			if(m[c]==false){m[c]=true;printf("%c",c);}
		}
		printf("\n");
		m.clear();
	}
	return 0;
}