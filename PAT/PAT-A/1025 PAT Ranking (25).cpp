#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
//zhicheng
//August 8,2018
typedef struct{string num;int sco;int fin_rank;int flg;int loc_rank;}D;
vector<vector<D> > re;
vector<D> te; 
bool comp(D a,D b)
{
	if(a.fin_rank!=b.fin_rank) return a.fin_rank<b.fin_rank;
	else return a.num<b.num;
}
void local_sort(int b[])
{
	int rank[101]={0},numb=0;
	for(int i=100;i>=0;i--)
	{
		if(b[i])
		{
			rank[i]=numb+1;
			numb+=b[i];
		}
	}
	for(int i=0;i<te.size();i++) te[i].loc_rank=rank[te[i].sco];
}
void final_sort(int c[])
{
	int rank[101]={0},numb=0;
	for(int i=100;i>=0;i--)
	{
		if(c[i])
		{
			rank[i]=numb+1;
			numb+=c[i];
		}
	}
	for(vector<vector<D> >::iterator it=re.begin();it!=re.end();++it)
	{
		for(int i=0;i<(*it).size();++i) {(*it)[i].fin_rank=rank[(*it)[i].sco];te.push_back((*it)[i]);}
		(*it).clear();
	}
}
int main()
{
	//freopen("1.txt","r",stdin);
	int n,k,final[101]={0},local[101]={0},fg=1;
	scanf("%d",&n);
	while(n--)
	{
		memset(local,0,sizeof(local));
		scanf("%d",&k);
		while(k--)
		{
			D tmp;
			cin>>tmp.num>>tmp.sco;
			tmp.flg=fg;
			local[tmp.sco]++;
			final[tmp.sco]++;
			te.push_back(tmp);
		}
		local_sort(local);
		re.push_back(te);
		te.clear();
		fg++;
	}
	final_sort(final);
	sort(te.begin(),te.end(),comp);
	cout<<te.size()<<endl;
	for(int i=0;i<te.size();i++)cout<<te[i].num<<" "<<te[i].fin_rank<<" "<<te[i].flg<<" "<<te[i].loc_rank<<endl;
	te.clear();
	return 0;
}
