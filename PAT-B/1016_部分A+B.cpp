/**
	正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。
	例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
	现给定A、DA、B、DB，请编写程序计算PA + PB。
	
	输入格式： 
	输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
	输出格式： 
	在一行中输出PA + PB的值。 

	输入样例1：
	3862767 6 13530293 3
	输出样例1：
	399
	输入样例2：
	3862767 1 13530293 8
	输出样例2：
	0
**/
//zhicheng
//Mar.10,2018 12min42second
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int _fun(string a,int b)
{
	vector<int> s; 
	for(int i=0;i<a.length();i++)	s.push_back(a[i]-'0');
	int n=count(s.begin(),s.end(),b);
	int p=0;
	for(int i=0;i<n;i++) p=p*10+b;
	return p;
}

int main()
{
	string A,B;
	int DA,DB;
	while(cin>>A>>DA>>B>>DB)
	{
		int pa=_fun(A,DA);
		int pb=_fun(B,DB);
		cout<<pa+pb<<endl; 
	} 
	return 0;
} 
