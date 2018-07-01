/**
 * 1016. 部分A+B (15)
 * https://www.nowcoder.com/pat/6/problem/4042
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jun.30,2018

int fun(string s,char ds)
{
	int te=0;
	for(int i=0;i<s.length();i++)
		if(s[i]==ds) te=te*10+(ds-'0');
	return te;
}

int main()
{
	string a,b;
	char da,db;
	while(cin>>a>>da>>b>>db)
		cout<<fun(a,da)+fun(b,db)<<endl;
	return 0;
}