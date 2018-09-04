/*
	科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，
	其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，
	即数字的整数部分只有1位，小数部分至少有1位，
	该数字及其指数部分的正负号即使对正数也必定明确给出。
	现以科学计数法的格式给出实数A，
	请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。
	
	输入格式： 
	每个输入包含1个测试用例，即一个以科学计数法表示的实数A。
	该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。
	输出格式： 
	对每个测试用例，在一行中按普通数字表示法输出A，
	并保证所有有效位都被保留，包括末尾的0。
	
	输入样例1：
	+1.23400E-03
	输出样例1：
	0.00123400
	输入样例2：
	-1.2E+10
	输出样例2：
	-12000000000
*/
//zhicheng
//Mar.16,2018
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//移动小数点操作
void _jisuan(string tt)
{
	int cnt;//存放E的下标
	for(int i=0;i<tt.length();i++)
		if(tt[i]=='E') {cnt=i;break;}
	int temp = 0;//存放指数的系数
	for(int i=cnt+2;i<tt.length();i++)
		temp=temp*10+tt[i]-'0';
	switch(tt[cnt+1])
	{
		case '-':
			// output
			if(temp) cout<<"0.";
			for(int i=1;i<temp;i++)
				cout<<"0";
			for(int i=1;i<cnt;i++)
			{
				if(tt[i]=='.'&& temp) continue;
				cout<<tt[i];
			}
			break;
		 case '+':
		 	if(temp<=cnt-3)
		 		for(int i=1;i<cnt;i++)
		 		{
		 			if(tt[i]=='0' && i==1 && temp) continue;
		 			if(tt[i]=='.' && temp) continue;
		 			cout<<tt[i];
		 			if(i==2+temp && temp!=cnt-3 && temp) cout<<"."; 
		 		}
		 	else 
		 	{
		 		for(int i=1;i<cnt;i++)
		 		{
		 			if(tt[i]=='0' && i==1 && temp) continue;
		 			if(tt[i]=='.' && temp) continue;
		 			cout<<tt[i];
		 		}
		 		for(int i=0;i<temp-cnt+3;i++)
		 			cout<<"0";
		 	}
		 	break;
	}
	cout<<endl;
}

int main()
{
	string ss;
	while(cin>>ss)
	{
		if(ss[0]=='-') cout<<"-";
		_jisuan(ss);
	}
	return 0;
}