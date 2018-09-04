/**
 * 1015 反转链表 (25)
 * https://www.nowcoder.com/pat/6/problem/4051
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100000;
int data[maxn],nex[maxn],id[maxn];
//zhicheng
//Jul.8,2018
int main()
{
	freopen("1.txt","r",stdin);
	int head,n,k;
	while(cin>>head>>n>>k)
	{
		//构造静态链表
		for(int i=0;i<n;i++)
		{
			int te1,te2,te3;
			cin>>te1>>te2>>te3;
			data[te1]=te2;
			nex[te1]=te3;
		}
		// for(int i=head;i!=-1;i=nex[i]) printf("%05d %d %05d\n",i,data[i],nex[i]);
		int q=head,len=0;
		while(q!=-1){id[len++]=q;q=nex[q];}
		for(int cn=0,i=0;i<len/k;cn+=k,i++)//将参与翻转的部分进行翻转
		{
			reverse(id+cn,id+cn+k);
		}
		for(int i=0;i<len-1;i++)
		{
			printf("%05d %d %05d\n",id[i],data[id[i]],id[i+1]);
		}	
		printf("%05d %d -1\n",id[len-1],data[id[len-1]]);//最后一个结点的下个结点一定为空，即地址为-1		
	}
	return 0;
}