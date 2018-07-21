/**
 * 1005 Spell It Right (20)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
//zhicheng
//Jul.21,2018
string m[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten"};
string itos(long long n)
{
	string ss;
	if(n==0) return "0";
	while(n){ss.push_back(n%10+'0');n/=10;}
	return ss;
}
int main()
{
	string ss;
	while(cin>>ss)
	{
		long long sum=0;
		for(int i=0;i<ss.length();i++)sum+=ss[i]-'0';
		ss=itos(sum);
		for(int i=ss.length()-1;i>=0;i--){if(i!=ss.length()-1)printf(" ");cout<<m[ss[i]-'0'];}
		printf("\n");
	}
	return 0;
}
