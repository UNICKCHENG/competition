/**
	让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），
	换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。
	
	输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。
	输出格式：每个测试用例的输出占一行，用规定的格式输出n。
	
	输入样例1：
	234
	输出样例1：
	BBSSS1234
	输入样例2：
	23
	输出样例2：
	SS123
*/
//zhicheng
//Mar.5,2018  6min28second
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a;
	while(cin>>a)
	{
		int len=a.length();
		int test[len];
		for(int i=0;i<len;i++)
		{
			test[i]=a[i]-'0';
		}
		switch(len)
		{
			case 1:
				for(int i=1;i<=test[0];i++) cout<<i;
				break;
			case 2:
				for(int i=0;i<test[0];i++) cout<<"S";
				for(int i=1;i<=test[1];i++) cout<<i;
				break;
			case 3:
				for(int i=0;i<test[0];i++) cout<<"B";
				for(int i=0;i<test[1];i++) cout<<"S";
				for(int i=1;i<=test[2];i++) cout<<i;
				break;
			default:
				return 0 ;
				break;
		}
		cout<<endl;
	}
	return 0;
}
