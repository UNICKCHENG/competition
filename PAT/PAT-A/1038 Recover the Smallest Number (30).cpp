/**
 * 1038 Recover the Smallest Number (30)（30 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805449625288704
 * 题目大意:给定一组数,自由组合,要求组成一串最小的数
 * 解题思路:主要在于两点.其一,给这一组数进行排序;其二,组成的数字开头不可为0.
 */
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
// zhicheng
// August 21,2018
const int maxn=10000+5;
string a[maxn];
bool com(string p,string q) {return p+q<q+p;}// 给数字进行排序
int main()
{
	// freopen("1.in","r",stdin);
	int _,n;bool flg=false;
	for(scanf("%d",&_),n=_;_;_--) cin>>a[_];
	sort(a+1,a+n+1,com);
	for(int i=1;i<=n;i++)
	{ // 组成的数字开头不可为0
		if(flg==false)
		{
			int cnt=0;
			while(a[i][cnt]=='0') cnt++;
			if(a[i][cnt]!='\0') {while(a[i][cnt]!='\0') printf("%c",a[i][cnt++]);flg=true;}
		}
		else printf("%s",a[i].c_str());
	}
	if(flg==false) printf("0");// 为0的特殊情况处理
	printf("\n");
	return 0;
}
