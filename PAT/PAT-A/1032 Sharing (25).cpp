/**
 * 1032 Sharing (25)（25 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805460652113920
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//August 14,2018
const int maxn=100000+5;
int ne[maxn],flg[maxn];//分别ne代表next,flg表示该节点是否遍历过
int main()
{
	int start_a,start_b,n,id,nextt;char data;
	scanf("%d %d %d",&start_a,&start_b,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %c %d",&id,&data,&nextt);
		ne[id]=nextt;
		flg[id]=false;
	}
	int re=-1;
	for(int i=start_a;i!=-1;i=ne[i])  flg[i]=true;// 从给定的第一组开始节点出发,遍历该组的全部节点
	for(int i=start_b;i!=-1;i=ne[i])  if(flg[i]==true){re=i;break;}// 从给定的第二组节点出发,如若遇到第一组中已经遍历过的节点,则此节点为输出结果
	if(re<0) printf("-1\n");// 如若两组无公共节点的话,则输出-1
	else printf("%05d\n",re);
	return 0;
}
