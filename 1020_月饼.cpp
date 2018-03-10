/**
	月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。
	现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。 
	注意：销售时允许取出一部分库存。样例给出的情形是这样的：
	假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。
	如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。

	输入格式： 
	每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
	输出格式： 
	对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。

	输入样例：
	3 20
	18 15 10
	75 72 45
	输出样例：
	94.50
**/

//zhicehng 
//Mar.10,2018 
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef struct data
{
	double numb;
	double price;
}Data;


bool comp(Data a,Data b)
{
	double a1=a.price*1.0/a.numb;
	double a2=b.price*1.0/b.numb;
	if(a1>=a2) return a1>a2;
	return a2<a1;
}

int main()
{
	int N,D;
	while(cin>>N>>D)
	{
		Data a[N];
//input the information
		for(int i=0;i<N;i++) cin>>a[i].numb;
		for(int i=0;i<N;i++) cin>>a[i].price;
		sort(a,a+N,comp);
	//	for(int i=0;i<N;i++) cout<<a[i].numb<<" "<<a[i].price<<endl;//test

//operation 
		double all_numb=0;
		double all_price=0;
		for(int i=0;i<N;i++)
		{
			all_numb+=a[i].numb;
			all_price+=a[i].price;
			if(all_numb<D) continue;
			else 
			{
				double temp=all_numb-D;	//多出需求的量 
				all_price-=a[i].price*(temp*1.0/a[i].numb); 
				break;
			}
		}
		printf("%.2lf\n",all_price);
	}
	return 0;
}
