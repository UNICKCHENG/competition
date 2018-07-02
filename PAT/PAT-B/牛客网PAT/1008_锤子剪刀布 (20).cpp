/**
 * 1008	锤子剪刀布 (20)
 * https://www.nowcoder.com/pat/6/problem/4044
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jul.2,2018
char judge(int* a)
{
	if(a[2]>=a[0]&&a[2]>=a[1]) return 'B';
	if(a[0]>a[2]&&a[0]>=a[1]) return 'C';
	return 'J';
}

int main()
{
	int n;
	freopen("1.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		char a,b;
		int win[3]={0},lose[3]={0};//分别表明胜败次数
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			//相等分布，此步一定得放至开头进行判断
			if(a==b) continue;
			//C B分布
			if(a-b==-1||a-b==1)  a=='B'?win[2]++:lose[2]++;
			//J C分布
			else if(a=='C'||b=='C')   a=='C'?win[0]++:lose[0]++;
			//J B分布
			else if(a=='B'||b=='B')   a=='J'?win[1]++:lose[1]++;
		}
		int w=win[0]+win[1]+win[2];
		int l=lose[0]+lose[1]+lose[2];
		int d=n-w-l;
		printf("%d %d %d\n%d %d %d\n",w,d,l,l,d,w);
		printf("%c %c\n",judge(win),judge(lose));
	}
	return  0;
}