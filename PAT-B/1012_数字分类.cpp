/**
	给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
	A1 = 能被5整除的数字中所有偶数的和； 
	A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...； 
	A3 = 被5除后余2的数字的个数； 
	A4 = 被5除后余3的数字的平均数，精确到小数点后1位； 
	A5 = 被5除后余4的数字中最大数字。 

	*输入格式： 
	每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，
	随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
	*输出格式： 
	对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。
	数字间以空格分隔，但行末不得有多余空格。
	若其中某一类数字不存在，则在相应位置输出“N”。

	输入样例1：
	13 1 2 3 4 5 6 7 8 9 10 20 16 18
	输出样例1：
	30 11 2 9.7 9
	输入样例2：
	8 1 2 4 5 6 7 9 16
	输出样例2：
	N 11 2 N 9
**/ 

//zhicheng
//Mar.9,2018 
//------------------------------------------------------------------------------ 
//注意点：处理不存在的情况，不能仅仅用结果0来衡量，要考虑A2中特殊的情况，即A2的结果可能是两个相等的数，致使结果为0 
#include<iostream>
#include<cstdio>
using namespace std;

long long num[5];
double numb;//处理被5除后余3的数字的平均数，精确到小数点后1位的情况 
int count1=0;//将被5除后余1的数字按给出顺序进行交错求和标记位 

void fun(int m)
{
	switch(m%5)
	{
		case 0://能被5整除的数字中所有偶数的和
			if(m%2==0) num[0]+=m;
			break;
			
		case 1://将被5除后余1的数字按给出顺序进行交错求和
			if(!(count1%2)) num[1]+=m;
			else         num[1]-=m;
			count1++;
			break;
		case 2://被5除后余2的数字的个数 
			num[2]++;
			break;
		case 3://被5除后余3的数字的平均数，精确到小数点后1位
			static int count2=1;
			num[3]+=m;
			numb=num[3]*1.0/count2;
			count2++;
			break;
		case 4://被5除后余4的数字中最大数字
			if(m>num[4]) num[4]=m;
			break;
	}
}

int main()
{
	int n;
	cin>>n;
	num[5]={0};
	int a[n];
	//input and deal
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		fun(a[i]);//judeg and deal
	}
	//output
	for(int i=0;i<5;i++)
	{
		if(i==1&&count1==0){cout<<"N ";continue;} 
		if(!num[i]&&i!=1){cout<<"N";}
		else
		{
			if(i==3){printf("%.1lf ",numb);continue;}
			cout<<num[i];	
		}
		if(i!=4) cout<<" ";
		else    cout<<endl;
	}
	return 0;
}
