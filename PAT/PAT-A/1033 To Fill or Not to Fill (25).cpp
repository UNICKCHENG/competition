/**
 * 1033 To Fill or Not to Fill (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805458722734080
*/ 
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// zhicheng
// August 16,2018
typedef struct{float pri;float dis;}D;
float c,d,da;int n;
vector<D> a;

bool comp(D a,D b){return a.dis<b.dis;}

int fun(int k)
{
	int cnt=0;float minpri=0;
	if(a[k+1].dis>a[k].dis+600) return -1;
	for(int i=k+1;i<=n&&a[i].dis<=a[k].dis+600;i++)
	{
		if(minpri==0||minpri>a[i].pri) {cnt=i;minpri=a[i].pri;}
		if(a[i].pri<a[k].pri) return i;
	}
	return cnt;
}
int main()
{
	// freopen("1.txt","r",stdin);
	float best_pri=0;D tmp;float distance;
	scanf("%f %f %f %d",&c,&d,&da,&n);
	for(int i=0;i<n;i++) {scanf("%f %f",&tmp.pri,&tmp.dis);a.push_back(tmp);}
	tmp.dis=d;tmp.pri=0;a.push_back(tmp);
	sort(a.begin(),a.end(),comp);
	if(a[0].dis!=0) {printf("The maximum travel distance = 0.00\n");return 0;}
	int cn;double cmax=0;
	for(cn=0;cn<n&&cn!=-1;) 
	{
		int start=cn;
		cn=fun(cn);
		if(cn==-1) 
		{
			distance=a[start].dis+c*da;
			break;
		}
		if(a[start].pri<a[cn].pri)
		{
			best_pri+=a[start].pri*(c-cmax);
			cmax=c-(a[cn].dis-a[start].dis)/da;
		}
		else
		{
			best_pri+=a[start].pri*((a[cn].dis-a[start].dis)-cmax*da)/da;
			cmax=0;
		}
	}
	if(cn==-1) printf("The maximum travel distance = %.2f\n",distance);
	else printf("%.2f\n",best_pri);
	return 0;
}
