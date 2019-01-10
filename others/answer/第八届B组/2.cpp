#include<iostream>
using namespace std;

bool is_Prime(int n)
{
	for(int i=2;i<=n/i;i++)
		if(!(n%i)) return false;
	return true;
}

int main()
{
	for(int a=2;a<1000;a++)
	{
		for(int n=2;n<1000;n++)
		{
			if(is_Prime(n)
				&&is_Prime(n+a)
				&&is_Prime(n+2*a)
				&&is_Prime(n+3*a)
				&&is_Prime(n+4*a)
				&&is_Prime(n+5*a)
				&&is_Prime(n+6*a)
				&&is_Prime(n+7*a)
				&&is_Prime(n+8*a)
				&&is_Prime(n+9*a)) {cout<<a<<endl; break;}
		}
	}
	return 0;
}