#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=6;
int mapp[maxn][maxn];
int mark[maxn];
int dist[maxn];

/*----------------Dijkstra最短路径算法------------------------------*/
void Dijkstra(int n,int start)
{
	int k=start;
	for(int i=0;i<n;i++)
	{
		mark[i]=0;
		dist[i]=mapp[start][i];
	}
	mark[start]=1;
	dist[start]=0;
	for(int i=0;i<n;i++)
	{
		int min=99999999;
		for(int j=0;j<n;j++)
		{
			if(!mark[j]&&min>dist[j])
			{
				min=dist[j];
				k=j;
			}
		}
		mark[k]=1;
		for(int j=0;j<n;j++)
		{
			if(!mark[j]&&dist[j]>mapp[start][k]+mapp[k][j])
				dist[j]=mapp[start][k]+mapp[k][j];
		}
	}
}
/*----------------Dijkstra最短路径算法------------------------------*/

/*---------------插点求最短路径算法---------------------------------*/
void floyd()
{
	int b[maxn][maxn];
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)
			for(int k=0;k<maxn;k++)
			{
				if(k==0) b[i][j]=mapp[i][j];
				else
				{
					b[i][j]=min(mapp[i][j],mapp[i][k]+mapp[k][j]);
				}
			}
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
}
/*---------------插点求最短路径算法---------------------------------*/

int main()
{
	freopen("1.txt","r",stdin);
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)
		{
			cin>>mapp[i][j];
		}
	Dijkstra(maxn,1);//Dijkstra求最短路径
	floyd();//Floyd求最短路径
	for(int i=0;i<maxn;i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	return 0;
}