#include<cstdio>
#include<iostream>
using namespace std;

void twoSum(int* data,unsigned int length,int sum)
{
	int begin=0,end=length-1;
	long long Cursum;
	while(begin<end)
	{
		Cursum=data[begin]+data[end];
		if(Cursum==sum)
		{
			cout<<data[begin]<<" "<<data[end]<<"\n";
			//begin++;
			//end--;
			return;
		}
		else 
		{
			if(Cursum<sum) begin++;
			else end--;
		}
	}
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int size=sizeof(a)/sizeof(int);
	// cout<<size;
	twoSum(a,size,12);
	return 0;
}