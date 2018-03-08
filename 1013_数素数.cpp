/*
	令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

	输入格式： 
	输入在一行中给出M和N，其间以空格分隔。

	输出格式： 
	输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

	输入样例：
	5 27
	输出样例：
	11 13 17 19 23 29 31 37 41 43
	47 53 59 61 67 71 73 79 83 89
	97 101 103
*/
//zhicheng
//Mar.8,2018 30 min 22 second
#include<iostream>
using namespace std;

//judge to prime 
bool is_Prime(int n)
{
	for(int i=2;i<=n/i;i++)
	{
		if(!(n%i)) return false;
	}
	return true;
}

int main()
{
	int m,n;
	while(cin>>m>>n&&m&&n)
	{
		int vis=0;//换行 
		for(int i=2;;i++)
		{
			static int count=0;
			if(!is_Prime(i)) continue;
			count++;
			if(count<m)continue;
			if(count>n) break;
			if(count>=m||count<=n)
			{
				if(count==n) {cout<<i<<endl;break;}
				if(vis<9)
				{
					cout<<i<<" ";
					vis++;
				}
				else
				{
					cout<<i<<endl;
					vis=0;
				} 
			}
		}
	}
	return 0;
}
