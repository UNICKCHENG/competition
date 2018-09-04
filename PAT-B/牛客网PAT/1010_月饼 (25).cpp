/**
 * 1010	月饼 (25)
 * https://www.nowcoder.com/pat/6/problem/4046
 * 耗时：27min
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//zhicheng
//Jul.4,2018 
typedef struct {int num;int pri;}D;
vector<D>a;

bool comp(D p,D q){	return (p.pri*1.0/p.num)>(q.pri*1.0/q.num);}

int main()
{
	freopen("1.txt","r",stdin);
	int n,m;
	while(cin>>n>>m)
	{
		D te;double sum=0;
		for(int i=0;i<n;i++) {cin>>te.num;a.push_back(te);}
		for(int i=0;i<n;i++) {cin>>te.pri;a[i].pri=te.pri;}
		sort(a.begin(),a.end(),comp);//按单价的大小从高到低排序
		int cnt=0;
		//for(int i=0;i<n;i++) cout<<a[i].num<<" "<<a[i].pri<<endl;
		while(m)
		{
			if(m<=a[cnt].num) {sum+=m*(a[cnt].pri*1.0/a[cnt].num);m=0;}
			else {m-=a[cnt].num;sum+=a[cnt].pri;}
			cnt++;
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}