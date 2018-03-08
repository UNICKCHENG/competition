/*
	给定区间[-231, 231]内的3个整数A、B和C，请判断A+B是否大于C。 

	输入格式： 
	输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。
	输出格式： 
	对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。

	输入样例：
	4
	1 2 3
	2 3 4
	2147483647 0 2147483646
	0 -2147483648 -2147483647

	输出样例：
	Case #1: false
	Case #2: true
	Case #3: true
	Case #4: false
*/
//zhicheng
//Mar.8 2018
#include<iostream>
using namespace std;

int is_Ture(long long a,long long b,long long c)
{
	if(a+b>c) return 1;
	else      return 0;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int flg[n];
		int num=n;
		int count=1;
		long long A,B,C;
		do
		{
			cin>>A>>B>>C;
			flg[num]=is_Ture(A,B,C); 
		}while(--num);
		for(int i=n;i>0;i--)
		{
			if(flg[i]) cout<<"Case #"<<count<<": true"<<endl;
			else    cout<<"Case #"<<count<<": false"<<endl;
			count++;
		}
	}
	return 0;
}
