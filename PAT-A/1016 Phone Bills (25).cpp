/**
 * 1016 Phone Bills (25)（25 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805493648703488
 * https://www.nowcoder.com/pat/1/problem/4012
 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//zhicheng
//Aug.2,2018
const double EPS=10e-6;
typedef struct {
	string name;
	vector<string> data;
	map<string,bool> fg;
}D;
map<string,int> ve;
vector<D> re;
int rate[24];
bool comp(D a,D b){return a.name<b.name;}
void clear(){ve.clear(),re.clear();}

//input the phone cell records
void input(string na,string da,string flg,int& cnt)
{
	D tmp;tmp.name=na;
	if(!ve[na]){re.push_back(tmp);ve[na]=cnt++;}//if it doesn't exit,we will creat the space for it
	re[ve[na]-1].data.push_back(da);//now,it already exits;
	if(flg!="off-line")re[ve[na]-1].fg[da]=true;
	else re[ve[na]-1].fg[da]=false;
}

double op_time(string a,string b)
{
	double p=0;
	for(int i=0;i<24;i++) p+=60*rate[i];
	double pri=0;
	int time1[4]={0},time2[4]={0},cn=0;
	for(int i=0;i<a.length();i++) {if(a[i]==':'){cn++;i++;} time1[cn]=time1[cn]*10+a[i]-'0';}
	cn=0;
	for(int i=0;i<b.length();i++) {if(b[i]==':'){cn++;i++;} time2[cn]=time2[cn]*10+b[i]-'0';}
	printf("%02d:%02d:%02d %02d:%02d:%02d ",time1[1],time1[2],time1[3],time2[1],time2[2],time2[3]);
	printf("%d ",(time2[1]-time1[1])*24*60+(time2[2]-time1[2])*60+time2[3]-time1[3]);
	pri+=(time2[1]-time1[1])*p;//to prevent different days
	if(time2[2]>time1[2]) pri+=(60-time1[3])*rate[time1[2]]+time2[3]*rate[time2[2]];
	else if(time2[2]<time1[2])pri-=(60-time2[3])*rate[time2[2]]+time1[3]*rate[time1[2]];
	else pri+=(time2[3]-time1[3])*rate[time2[2]];
	for(int i=time1[2]+1;i<time2[2];i++) pri+=60*rate[i];
	for(int i=time2[2]+1;i<time1[2];i++) pri-=60*rate[i];
	return pri/100;
}
double op(D a)
{
	double sum_pri=0;
	for(int i=0;i<a.data.size()-1;i++)
	{
		if(!a.fg[a.data[i]]) continue;
		if(a.fg[a.data[i+1]]) continue;
		double pri=op_time(a.data[i],a.data[i+1]);
		printf("$%.2lf\n",pri);
		sum_pri+=pri;
		i++;
	}
	return sum_pri;
}
bool is_True(D a)
{
	if(a.data.size()<=1) return false;
	for(int i=0;i<a.data.size()-1;i++)
	{
		if(!a.fg[a.data[i]]) continue;
		if(a.fg[a.data[i+1]]) continue;
		return true;
	}
	return false;
}
int main()
{
	//freopen("1.txt","r",stdin);
	int n,cnt=1;
	string na,flg,da;
	for(int i=0;i<24;i++) scanf("%d",&rate[i]);//input the rate structure
	scanf("%d",&n);
	//input N date about the phone cell records
	for(int i=1;i<=n;i++)
	{
		string na,da,flg;//name,mm:dd:hh:mm,on-line/off-line,respectively
		cin>>na>>da>>flg;
		input(na,da,flg,cnt);
	}
	sort(re.begin(),re.end(),comp);// The name of Phone calls are sorted by dictionary order
	//print a phone bill for each customer.
	for(int i=0;i<re.size();i++)
	{
		sort(re[i].data.begin(),re[i].data.end());
		if(!is_True(re[i])) continue; 
		int month=0;
		for(int j=0;j<re[i].data[0].length();j++) {if(re[i].data[0][j]==':') break;month=month*10+re[i].data[0][j]-'0';}
		cout<<re[i].name;printf(" %02d\n",month);
		double pri=op(re[i]);
		printf("Total amount: $%.2lf\n",pri);
	}
	return 0;
}
