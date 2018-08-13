/**
 * 1029 Median（25 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805466364755968
 */
#include<cstdio>
#include<iostream>
#include <climits>
#include<vector>
using namespace std;
//zhicheng
//August 13,2018
vector<int> a;

bool is_judge(int cn,int mid,int n)
{
	if(cn==mid) {printf("%d\n",n);return true;}
	return false;
}
int main()
{
	// freopen("1.txt","r",stdin);
	long long int tmp;int len[2],cnt=0,mid;
	scanf("%d",&len[0]);
	for(int i=0;i<len[0];i++){scanf("%lld",&tmp);tmp=min((long long int)INT_MAX,tmp);a.push_back(tmp);}
	scanf("%d",&len[1]);
	if((len[0]+len[1])%2==0) mid=(len[0]+len[1])/2-1;
	else mid=(len[0]+len[1])/2;
	int cn=0;
	while(len[1]--)
	{
		bool flg=false;
		scanf("%lld",&tmp);
		tmp=min((long long int)INT_MAX,tmp);
		while(cnt<len[0]&&a[cnt]<=tmp){is_judge(cn,mid,a[cnt]);cn++;cnt++;}
		is_judge(cn,mid,tmp);
		cn++;
	}
	if(cnt<len[0]) 
		while(cnt<len[0])
		{
			if(is_judge(cn,mid,a[cnt])) break;
			cn++;
			cnt++;
		}
	a.clear();
	return 0;
}
