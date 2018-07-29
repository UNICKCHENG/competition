/**
 * The Best Rank (25)
 * PTA:https://pintia.cn/problem-sets/994805342720868352/problems/994805502658068480
 * nowcoder:https://www.nowcoder.com/pat/1/problem/3992
 */
 
 /*PAT can ＡＣ this code, but the nowcoder doesn't*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
//zhicheng
//Jul.29,2018
const int maxn=2000+5;
double a[maxn][5];
vector<double> p[5];
map<double,int> fg,re[4];
int main()
{
	//freopen("1.txt","r",stdin);
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		int cnt=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<4;j++){scanf("%lf",&a[i][j]);}
			a[i][4]=(a[i][1]+a[i][2]+a[i][3])/3;
			for(int j=1;j<=4;j++) p[j].push_back(a[i][j]);
			fg[a[i][0]]=cnt++;
		}
		for(int i=1;i<=4;i++)sort(p[i].begin(),p[i].end(),greater<double>());
		for(int i=0;i<n;i++){if(re[3][p[4][i]])continue; re[3][p[4][i]]=i+1;}
		for(int i=0;i<n;i++){if(re[0][p[1][i]])continue; re[0][p[1][i]]=i+1;}
		for(int i=0;i<n;i++){if(re[1][p[2][i]])continue; re[1][p[2][i]]=i+1;}
		for(int i=0;i<n;i++){if(re[2][p[3][i]])continue; re[2][p[3][i]]=i+1;}
		for(int i=0;i<m;i++)
		{
			double tmp;
			scanf("%lf",&tmp);
			if(!fg[tmp]){printf("N/A\n");continue;}
			int A,C,M,E;	
			A=re[3][a[fg[tmp]-1][4]];C=re[0][a[fg[tmp]-1][1]];M=re[1][a[fg[tmp]-1][2]];E=re[2][a[fg[tmp]-1][3]];
			if(A<=C&&A<=M&&A<=E) printf("%d A\n",A);
			if(C<A&&C<=M&&C<=E) printf("%d C\n",C);
			if(M<C&&M<A&&M<=E) printf("%d M\n",M);
			if(E<A&&E<M&&E<C) printf("%d E\n",E);
		}
	}
	return 0;
}
