/**
 * 1038 Recover the Smallest Number (30)（30 point(s)）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805449625288704
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
bool com(string p,string q) {return p+q<q+p;}
int main()
{
	// freopen("1.in","r",stdin);
	int _,n;bool flg=false;
	for(scanf("%d",&_),n=_;_;_--) cin>>a[_];
	sort(a+1,a+n+1,com);
	for(int i=1;i<=n;i++)
	{
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
