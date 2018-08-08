/**
 * 1025 PAT Ranking (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872
 * https://www.nowcoder.com/pat/1/problem/4004
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//zhicheng
//August 8,2018
typedef struct{string num;int sco;int fin_rank;int flg;int loc_rank;}D;
vector<D> re;
vector<D> te; 
bool comp(D a,D b)
{
	if(a.sco!=b.sco) return a.sco>b.sco;
	else return a.num<b.num;
}
inline void _sort(vector<D>& a,int fg)
{
	sort(a.begin(),a.end(),comp);
	if(!fg) {a[0].loc_rank=1; re.push_back(a[0]);}
	else a[0].fin_rank=1;
	for(int i=1;i<a.size();i++)
	{
		if(!fg)
		{
			a[i].loc_rank=(a[i].sco==a[i-1].sco)?(a[i-1].loc_rank):(i+1);
			re.push_back(a[i]);
		}
		else 
		{
			a[i].fin_rank=(a[i].sco==a[i-1].sco)?(a[i-1].fin_rank):(i+1);
		}
	}
}

int main()
{
	freopen("1.txt","r",stdin);
	int n,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		D tmp;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			cin>>tmp.num>>tmp.sco;
			tmp.flg=i;
			te.push_back(tmp);
		}
		_sort(te,0);
		te.clear();
	}
	_sort(re,1);
	cout<<re.size()<<endl;
	for(int i=0;i<re.size();i++)cout<<re[i].num<<" "<<re[i].fin_rank<<" "<<re[i].flg<<" "<<re[i].loc_rank<<endl;
	re.clear();
	return 0;
}


------
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
