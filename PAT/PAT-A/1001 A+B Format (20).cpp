/**
 * 1001 A+B Format (20)（20 分）
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400
 */
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
//zhicheng
//Jul.5,2018
int main()
{
	int a,b;
	char re[15];
	while(cin>>a>>b)
	{
		int te=a+b,cn=0,cnt=0,flg=0;;
		if(te==0) {cout<<"0"<<endl;continue;}
		if(te<0){cn=1;te=(-1)*te;}
		memset(re,'\0',sizeof(re));
		while(te)
		{
			if(flg&&flg%3==0) {re[cnt++]=',';flg=0;}	
			re[cnt++]=te%10+'0';
			te/=10;
			flg++;
		}
		if(cn) cout<<"-";
		for(int i=strlen(re)-1;i>=0;i--) cout<<re[i];
		cout<<endl;
	}
	return 0;
}