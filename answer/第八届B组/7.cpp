#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct date
{
	int yy;
	int mm;
	int dd;
}D;
D re[3];
int cn=0;
int rm[12]={31,29,31,30,31,30,31,31,30,31,30,31};

bool comp(D a,D b)
{
	if(a.yy==b.yy)
		if(a.mm==b.mm) return a.dd<b.dd;
		else return a.mm<b.mm;
	return a.yy<b.yy;
}

void fun(int y,int m,int d)
{
		//年份
		if(y<60) y+=2000;
		else     y+=1900;
		//月份判定
		if(m>12||m<1) return;
		//日期判定
		if(d<1||d>rm[m-1]) return;
		//闰年特殊日子判定
		if(!((y%4==0&&y%100!=0)||(y%400==0)) && m==2 && d>28) return;
		re[cn].yy=y;
		re[cn].mm=m;
		re[cn++].dd=d;
}

int main()
{
	string ss;
	while(cin>>ss){
	int te[3];
	te[0]=(ss[0]-'0')*10+ss[1]-'0';
	te[1]=(ss[3]-'0')*10+ss[4]-'0';
	te[2]=(ss[6]-'0')*10+ss[7]-'0';
	if(te[0]!=te[2]) fun(te[0],te[1],te[2]);
	if(te[0]!=te[1]) fun(te[2],te[0],te[1]);
	fun(te[2],te[1],te[0]);
	sort(re,re+cn,comp);
	for(int i=0;i<cn;i++)
		printf("%d-%02d-%02d\n",re[i].yy,re[i].mm,re[i].dd);
	}
	return 0;
}