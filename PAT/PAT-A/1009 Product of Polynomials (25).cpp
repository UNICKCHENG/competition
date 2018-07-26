/**
 * 1009 Product of Polynomials (25)
 * PTA:https://pintia.cn/problem-sets/994805342720868352/problems/994805509540921344
 * nowcoder:https://www.nowcoder.com/pat/1/problem/3995
 */ 
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
//zhicheng
//Jul.26,2018
map<double,double> re;

bool input(map<double,double>& m)
{
	int n;double ex,co;
	if(scanf("%d",&n)!=1) return false;
	for(int i=0;i<n;i++){cin>>ex>>co;m[ex]=co;}
	return true;
}

void op(map<double,double> a,map<double,double> b)
{
	for(map<double,double>::iterator ita=a.begin();ita!=a.end();ita++)
		for(map<double,double>::iterator itb=b.begin();itb!=b.end();itb++)
			re[ita->first+itb->first]+=ita->second*itb->second;
}
int main()
{
	freopen("3.in","r",stdin);
	map<double,double> a,b;
	while(input(a)&&input(b))
	{
		int count=0;
		op(a,b);
		for(map<double,double>::iterator it=re.begin();it!=re.end();it++)//count the number of eligible
			if(it->second!=0) count++;
		printf("%d",count);
		for(map<double,double>::reverse_iterator it=re.rbegin();it!=re.rend();it++)
		{
			if(it->second==0)continue;
			printf(" %.lf %.1lf",it->first,it->second);
		}
		printf("\n");
		re.clear();
		a.clear();
		b.clear();
	}
	return 0;
}
