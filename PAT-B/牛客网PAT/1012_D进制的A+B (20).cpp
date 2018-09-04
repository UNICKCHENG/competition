/**
 * 1012	D进制的A+B (20)
 * https://www.nowcoder.com/pat/6/problem/4048
 * 耗时 10min
 */
#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
//zhicheng
//Jul.6,2018
stack<int> m;
void Hexadecimal(long long n,int k){ while(n){m.push(n%k);n/=k;}} 

int main()
{
	int a,b,d;
	while(scanf("%d %d %d",&a,&b,&d)!=EOF)
	{
		Hexadecimal(a+b,d);
		while(!m.empty())
		{
			if(m.top()>=10) cout<<'A'+m.top()-10;//D是小于十进制的可不需要此步骤
			else cout<<m.top();
			m.pop(); 
		}
		cout<<endl;
	}
	return 0;
}