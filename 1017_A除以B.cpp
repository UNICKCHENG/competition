/**
	本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
	输入格式： 
	输入在1行中依次给出A和B，中间以1空格分隔。 
	输出格式： 
	在1行中依次输出Q和R，中间以1空格分隔。 
	
	输入样例：
	123456789050987654321 7
	输出样例：
	17636684150141093474 3
**/
//zhicehng
//Mar.10,2018
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string A;
	int B;
	vector<int> Q;
	int R;
	while(cin>>A>>B)
	{
		if(A.length()==1){cout<<(A[0]-'0')/B<<" "<<(A[0]-'0')%B<<endl;continue;}
		R=A[0]-'0';
		for(int i=1;i<A.length();i++)
		{
			R=R*10+(A[i]-'0');
			Q.push_back(R/B);
			R=R%B;
		}
		for(int i=0;i<Q.size();i++) cout<<Q[i];
		cout<<" "<<R<<endl;
	}
	return 0;
} 
