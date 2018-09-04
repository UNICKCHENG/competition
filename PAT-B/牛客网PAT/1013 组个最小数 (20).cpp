/**
 * 1013	组个最小数 (20)
 * https://www.nowcoder.com/pat/6/problem/4049
 * 耗时：12min
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//zhicheng
//Jul.7,2018
vector<int >a;
int main()
{
	int te;
	for(int i=0;i<=9;i++)
	{
		cin>>te;
		for(int j=0;j<te;j++) a.push_back(i);
	}
	if(a[0]==0)
	{
		for(int i=1;i<a.size();i++)if(a[i]){te=i;break;}
		swap(a[0],a[te]);
	}
	for(int i=0;i<a.size();i++)cout<<a[i];
	cout<<endl;
	return 0;
}