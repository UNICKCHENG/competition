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
{// 寻找下一加油站地点
	int cnt=0;float minpri=0;
	if(a[k+1].dis>a[k].dis+c*da) return -1;
	for(int i=k+1;i<=n&&a[i].dis<=a[k].dis+c*da;i++)
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
	tmp.dis=d;tmp.pri=0;a.push_back(tmp); // 将终点纳入加油站行列,只不过油价为0
	sort(a.begin(),a.end(),comp);
	if(a[0].dis!=0) {printf("The maximum travel distance = 0.00\n");return 0;}// 如若起点无加油站,则车无法开驶至任何地方
	int cn;double cmax=0;
	for(cn=0;cn<n&&cn!=-1;) 
	{
		int start=cn;
		cn=fun(cn);
		if(cn==-1) 
		{// 下一加油站太远,油量不够
			distance=a[start].dis+c*da;
			break;
		}
		if(a[start].pri<a[cn].pri)
		{// 下一加油站油价大于此次加油站的,则在此加满油
			best_pri+=a[start].pri*(c-cmax);
			cmax=c-(a[cn].dis-a[start].dis)/da;
		}
		else
		{// 下一加油站油价不大于此次加油站的,则保证车刚刚好可以开驶至下个油站
			best_pri+=a[start].pri*((a[cn].dis-a[start].dis)-cmax*da)/da;
			cmax=0;
		}
	}
	if(cn==-1) printf("The maximum travel distance = %.2f\n",distance);
	else printf("%.2f\n",best_pri);
	return 0;
}
