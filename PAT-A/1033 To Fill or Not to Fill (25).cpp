/**
 * 1033 To Fill or Not to Fill (25)
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805458722734080
 * 题目大意:车要从起点开向终点,但是由于油箱容量有限,须在中途加油,因此途中将设立多个加油站,如何加油才可使路上所耗油费最低.
 *         如若车因油量不足无法到达终点,只须输出可行驶的最远距离
 * 解题思路:
 *        1.起始点须有加油站,因为车刚开始油箱为空
 *        2.寻找下一加油站B.在油箱满的情况下,从此时的加油站A出发,在不加油的情况下,依次遍历可行驶的最远距离内所有的加油站
 *            (1)若在此范围内,无加油站,表明无法行至终点,只须求可行驶的最远距离
 *            (2)若有加油站,应按距离的远近与此时的加油站A进行油价判断,第一个油价小于A油价的加油站为下一个加油地点B,
 *               并且在A加油时应保证车可以**刚刚好**开驶至B加油站;如若没有加油站的油价低于A处的,则选出此范围内油价最低的
 *               加油站为下一加油地点B,而在A处加油时,将油箱加满即可.
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
