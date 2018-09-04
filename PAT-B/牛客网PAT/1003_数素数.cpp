/** 1003	数素数 （20）
 **	https://www.nowcoder.com/pat/6/problem/4079
 */
#include<cstdio>
#include<iostream>
using namespace std;
//zhicheng
//Jun.27,2018
bool is_Prim(int n)
{
	if(n==1) return false;
	for(int i=2;i<=n/i;i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

int main()
{
	//freopen("1.txt","r",stdin);
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		int first=1,flg=1,cnt=0;//用于输出格式
		for(int i=2;;i++)
		{
			if(is_Prim(i))
			{
				cnt++;
				if(cnt<m) continue;
				if(cnt>n) break;
				if(flg>10) {printf("\n");first=1;flg=1;}
				if(first) { printf("%d",i);first=0;flg++;}
				else {printf(" %d",i);flg++;}
			}
		}
		cout<<endl;
	}
	return 0;
}