/*
	给定一个k位整数N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，
	请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。

	输入格式： 
	每个输入包含1个测试用例，即一个不超过1000位的正整数N。
	输出格式： 
	对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。

	输入样例：
	100311
	输出样例：
	0:2
	1:3
	3:1
*/
//zhicheng
//Mar.12,2018
#include<iostream>
using  namespace std;

void _comp(char a,int *cn)
{
	switch(a)
	{
		case '0':cn[0]++;break;
		case '1':cn[1]++;break;
		case '2':cn[2]++;break;
		case '3':cn[3]++;break;
		case '4':cn[4]++;break;
		case '5':cn[5]++;break;
		case '6':cn[6]++;break;
		case '7':cn[7]++;break;
		case '8':cn[8]++;break;
		case '9':cn[9]++;break;
	}
}

int main()
{
	string ss;
	while(cin>>ss)
	{
		int cnt[10]={0};
		for(int i=0;i<ss.length();i++)
			_comp(ss[i],cnt);//匹配字符出现的次数
		for(int i=0;i<10;i++)
		{
			if(cnt[i])
				cout<<i<<":"<<cnt[i]<<endl;
		}
	}
	return 0;
}