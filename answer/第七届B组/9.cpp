#include<stdio.h>

int main()
{
	long n,sum=0;
	scanf("%ld",&n);
	for(long i=1;i<=n;i++)
		sum+=i;
	printf("%ld",sum);
	return 0;
}
