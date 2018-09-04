/** 
 * 1027 在霍格沃茨找零钱（20）
 * https://www.nowcoder.com/pat/6/problem/4063
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.19,2018
inline long long sumn(int g,int s,int k){return (g*17+s)*29+k;}
inline void fun(long long t,int& g,int& s,int& k)
{
	k=t%29;t/=29;
	s=t%17;t/=17;
	g=t;
}
int main()
{
	int g1,s1,k1,g2,s2,k2,g,s,k;
	while(scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2)!=EOF)
	{
		long long t1=sumn(g1,s1,k1);
		long long t2=sumn(g2,s2,k2);
		if(t1<=t2) fun(t2-t1,g,s,k);
		else {printf("-");fun(t1-t2,g,s,k);}
		printf("%d.%d.%d\n",g,s,k);
	}
	return 0;
}