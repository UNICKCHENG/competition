/**
 * 1017 Queueing at Bank (25)（25 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805491530579968
 * https://www.nowcoder.com/pat/1/problem/4011
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//zhicheng
//Aug.3,2018
typedef struct{string time;float pro;}D;
vector<D> d,w;
bool comp(D a,D b){return a.time<b.time;}
float op_SubStrTime(string start,string end)
{
	int t1[3]={0},t2[3]={0},cn1=0,cn2=0;
	for(int i=0;i<start.length();i++){if(start[i]==':'){cn1++;i++;} t1[cn1]=t1[cn1]*10+start[i]-'0';}
	for(int i=0;i<end.length();i++){if(end[i]==':'){cn2++;i++;} t2[cn2]=t2[cn2]*10+end[i]-'0';}
	return ((t1[0]-t2[0])*60*60+(t1[1]-t2[1])*60+(t1[2]-t2[2]))*1.0/60;
}
string op_AddStrTime(string star,float p)
{
	int t[3]={0},cn=0;
	for(int i=0;i<star.length();i++){if(star[i]==':'){cn++;i++;} t[cn]=t[cn]*10+star[i]-'0';}
	int time=t[0]*60*60+t[1]*60+t[2]+(int)p*60;
	t[2]=time%60;time=time/60;
	t[1]=time%60;time=time/60;
	t[0]=time;
	star.clear();
	star.push_back(t[0]/10+'0');star.push_back(t[0]%10+'0');star.push_back(':');
	star.push_back(t[1]/10+'0');star.push_back(t[1]%10+'0');star.push_back(':');
	star.push_back(t[2]/10+'0');star.push_back(t[2]%10+'0');
	return star;
}
float op(D a,vector<D>& win)
{
	float time=0;
	sort(win.begin(),win.end(),comp);
	if(win[0].time>a.time)
	{
		time=op_SubStrTime(win[0].time,a.time);
		a.time=win[0].time;
	}
	win[0].time=op_AddStrTime(a.time,a.pro);
	//cout<<a.time<<" "<<a.pro<<endl;
	//cout<<a.time<<" "<<time<<endl;
	return time;
}
int main()
{
	//freopen("1.txt","r",stdin);
	int n,k;D tmp;float ave_wait_time=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){cin>>tmp.time>>tmp.pro;if(tmp.time>="17:00:01")continue;d.push_back(tmp);}
	sort(d.begin(),d.end(),comp);
	// for(int i=0;i<d.size();i++) cout<<d[i].time<<" "<<d[i].pro<<endl;
	for(int i=0;i<k;i++){tmp.time="08:00:00";tmp.pro=0;w.push_back(tmp);}
	for(int i=0;i<d.size();i++) ave_wait_time+=op(d[i],w);
	printf("%.1f\n",ave_wait_time/d.size());
	return 0;
}
