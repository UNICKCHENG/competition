/**
 * 1028 List Sorting (25)（25 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805468327690240
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
//zhicheng
//August 11,2018
typedef struct{int numb;char name[9];int sco;}D;
vector<D>a;
bool comp1(D a,D b){return a.numb<b.numb;}
bool comp2(D a,D b){if(strcmp(a.name,b.name)==0)return a.numb<b.numb;else return strcmp(a.name,b.name)<0;}
bool comp3(D a,D b){if(a.sco!=b.sco)return a.sco<b.sco;else return a.numb<b.numb;}
int main()
{
	// freopen("1.txt","r",stdin);
	int n,c;
	while(~scanf("%d %d",&n,&c))
	{
		a.clear();
		D tmp;
		for(int i=0;i<n;i++){scanf("%d %s %d",&tmp.numb,tmp.name,&tmp.sco);a.push_back(tmp);}
		if(c==1)sort(a.begin(),a.end(),comp1);
		else if(c==2)sort(a.begin(),a.end(),comp2);
		else if(c==3)sort(a.begin(),a.end(),comp3);
		for(int i=0;i<n;i++) printf("%06d %s %d\n",a[i].numb,a[i].name,a[i].sco);
	}
	return 0;
}
