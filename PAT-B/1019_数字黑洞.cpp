//zhicheng
//Mar.10,2018 21 min 28 second
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
 
//���� 
int _fun(int tt)
{
	int m[4];
	int a=0,b=0;
	for(int i=3;i>=0;i--)
	{
		m[i]=tt%10;
		tt=tt/10;
	}
	sort(m,m+4,greater<int>());//�Ӵ�С����
	for(int i=0;i<4;i++) a=a*10+m[i];
	sort(m,m+4,less<int>());//��С��������
	for(int i=0;i<4;i++) b=b*10+m[i];
	printf("%04d - %04d = %04d\n",a,b,a-b);
	
	return a-b;
} 

int main()
{
	int n;
	while(cin>>n)
	{
		int temp=n;
		if(temp%10==temp/10%10 && temp%10==temp/100%10  &&temp%10==temp/1000){printf("%04d - %04d = %04d\n",temp,temp,temp-temp);continue;}
		do
		{
			temp=_fun(temp);
		}while(temp!=6174);
	}
	return 0;
}
