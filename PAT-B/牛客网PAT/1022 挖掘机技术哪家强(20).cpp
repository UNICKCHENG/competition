/**
 * 1022 挖掘机技术哪家强(20)
 * https://www.nowcoder.com/pat/6/problem/4058
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
//zhicheng
//Jul.15,2018
typedef struct{int num;int sco;}D;
map<int ,int> m;
vector<D> re;
bool cmp(D a,D b){return a.sco>b.sco;}
void fun(int n,int s,int& k)
{
	D tmp;tmp.num=n;tmp.sco=s;
	if(m[n]==0) {m[n]=k++;re.push_back(tmp);}
	else re[m[n]-1].sco+=s;
}

int main()
{
	freopen("1.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int cnt=1;
		while(n--)
		{
			int numb,score;
			scanf("%d %d",&numb,&score);
			fun(numb,score,cnt);
		}
		sort(re.begin(),re.end(),cmp);
		printf("%d %d\n",re[0].num,re[0].sco);
		m.clear();
		re.clear();
	}
	return 0;
}


/*方案二
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
map<int,int>a;
int main()
{
	int n,x,y;
	while(scanf("%d",&n)!=EOF)
	{
		int maxn=0;
		while(n--)
		{
			scanf("%d %d",&x,&y);
			a[x]+=y;
			if(a[x]>a[maxn]) maxn=x;
		}
		printf("%d %d\n",maxn,a[maxn]);
		a.clear();
	}
	return 0;
}

*/