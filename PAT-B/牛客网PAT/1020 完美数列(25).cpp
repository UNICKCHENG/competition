/**
 * 1020	完美数列(25)
 * https://www.nowcoder.com/pat/6/problem/4056
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//zhicheng
//Jul.13,2018
vector<int> a;
int main()
{
	freopen("1.txt","r",stdin);
	int n,p;
	while(scanf("%d %d",&n,&p)!=EOF)
	{
		int temp,maxn=0;
		for(int i=0;i<n;i++){scanf("%d",&temp);a.push_back(temp);}
		sort(a.begin(),a.end());
		for(int i=0;i<n&&maxn<n-i;i++)
		{
			for(int j=i+maxn;j<n;j++)
			{
				if(a[j]>a[i]*p) break;
				maxn++;
			}
		}
		printf("%d\n",maxn);
		a.clear();
	}
	return 0;
}