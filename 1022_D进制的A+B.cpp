/*
	输入两个非负10进制整数A和B(<=230-1)，
	输出A+B的D (1 < D <= 10)进制数。 

	输入格式： 
	输入在一行中依次给出3个整数A、B和D。 
	输出格式： 
	输出A+B的D进制数。 

	输入样例：
	123 456 8
	输出样例：
	1103
*/
//zhicheng
//Mar.12,2018 18 min 32 second
#include<iostream>
#include<stack>
using namespace std;

//进制转换
void _fun(long long a,int b)
{
	stack<int> result;
	//push stack
	do
	{
		result.push(a%b);
		a/=b;
	}while(a);
	//output
	while(!result.empty())
	{
		cout<<result.top();
		result.pop();
	}
	cout<<endl;
}

int main()
{
	long long A,B;
	int D;
	while(cin>>A>>B>>D)
	{
		long long sum=A+B;
		_fun(sum,D);
	}
	return 0;
}