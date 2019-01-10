#include<iostream>
#include<cstdio>
using namespace std;


/*-------------------辗转相除法求最大公约数----------------*/
int gcd(int a,int b)
{
	int temp;
	while(a%b)
	{
		temp=a;
		a=b;
		b=temp%a;
	}
	return b;
}
/*-------------------辗转相除法求最大公约数----------------*/

/*-------------------辗转相除法求最小公倍数----------------*/
int lcm(int a,int b)
{
	int a1=a,b1=b,temp;
	while(a%b)
	{
		temp=a;
		a=b;
		b=temp%a;
	}
	return a1*b1/a;
}
/*-------------------辗转相除法求最小公倍数----------------*/
int main()
{
	cout<<gcd(12,9)<<" "<<lcm(12,9)<<endl;
}