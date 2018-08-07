/**
 * 1024 Palindromic Number (25)（25 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805476473028608
 * https://www.nowcoder.com/pat/1/problem/4005
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//zhicheng
//Aug.7,2018
inline bool is_Palindromic(string n)
{
	for(int i=n.length()-1,j=0;i>=j;i--,j++)
		if(n[i]!=n[j]) return false;
	return true;
}

inline void add(string& ss)
{
	int tmp=0;
	string te(ss.rbegin(),ss.rend());
	for(int i=ss.length()-1;i>=0;i--)
	{
		tmp=tmp+(ss[i]-'0')+(te[i]-'0');
		ss[i]=tmp%10+'0';
		tmp/=10;
	}
	if(tmp) ss.insert(0,1,tmp+'0');
}
int main()
{
	string n;int count=0,k;
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		if(is_Palindromic(n)) break;
		add(n);
		count++;
	}
	printf("%s\n%d\n",n.c_str(),count);
	return 0;
}
