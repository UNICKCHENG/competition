/**1002. 写出这个数 (20)
	读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。 
	输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。
	输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。 
	输入样例：
	1234567890987654321123456789
	输出样例：
	yi san wu
*/ 
//zhicheng
 
#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void print(string s)
{
	int select;
	for(int i=0;i<s.length();i++)
	{
		select=s[i]-'0';
		switch(select)
		{
			case 0:printf("ling");break;
			case 1:printf("yi");break;
			case 2:printf("er");break;
			case 3:printf("san");break;
			case 4:printf("si");break;
			case 5:printf("wu");break;
			case 6:printf("liu");break;
			case 7:printf("qi");break;
			case 8:printf("ba");break;
			case 9:printf("jiu");break;
		}
		printf("%c",i<s.length()-1?' ':'\n');
	}
}

int main()
{
  string n;
  int sum;
  while(cin>>n)
  {
  	sum=0;
  	//求和 
  	for(int i=0;i<n.length();i++)
  	{
  		sum+=n[i]-'0';
  	} 
  	//将从sum中提取出各个位的数字 
  	stringstream sout;
	string s;
	sout<<sum;
	s = sout.str();
//	cout<<s<<endl;//test s
	print(s);
  }
  
  return 0;
}

