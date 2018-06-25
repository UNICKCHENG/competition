#include<stdio.h>

int main()
{
	int i,j;//i==>age
	int a;
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			a=(j+1)*i+j*(j+1)/2;
			if(a==236) printf("%d\n",i);
		}
	}
	return 0;
}
