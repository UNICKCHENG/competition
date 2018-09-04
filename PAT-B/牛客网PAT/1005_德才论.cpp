/**
 * 1005 徳才论（25）
 * https://www.nowcoder.com/pat/6/problem/4041
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//zhicheng
//Jun.28,2018

struct Stu
{   int flg, numb, de, cai;};
vector<Stu> mm;

bool comp(struct Stu a,struct Stu b)
{
	if(a.flg!=b.flg) return a.flg<b.flg;
	if((a.de+a.cai)!=(b.de+b.cai)) return (a.de+a.cai)>(b.de+b.cai);
	if(a.de!=b.de) return a.de>b.de;
	return a.numb<b.numb;
}

int main()
{
	freopen("1.txt","r",stdin);
	int N,L,H;
	while(scanf("%d %d %d",&N,&L,&H)!=EOF)
	{
		Stu temp;
		for(int i=0;i<N;i++)
		{
			scanf("%d %d %d",&temp.numb,&temp.de,&temp.cai);
			if(temp.de<L||temp.cai<L) continue;
			if(temp.de>=H&&temp.cai>=H) temp.flg=1;
			else if(temp.de>=H&&temp.cai<H) temp.flg=2;
			else if(temp.de<H&&temp.de>=temp.cai) temp.flg=3;
			else temp.flg=4;
			mm.push_back(temp);
		}
		cout<<mm.size()<<endl;
		sort(mm.begin(), mm.end(), comp);//按类和总分排序
	    for (int i = 0; i < mm.size(); i++)
	            printf("%d %d %d\n", mm[i].numb, mm[i].de, mm[i].cai);
	    mm.clear();
	}
	return 0;
}
