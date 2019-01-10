//16
#include<stdio.h>

int main()
{
	int data[49];
	int sum=0;
	for(int i=0;i<49;i++) data[i]=i+1;//³õÊ¼»¯ 
	int i=11,j=28;
	for(int i=2;i<50;i++)
		for(int j=i+2;j<50;j++)
		{
			sum=0;
			for(int k=0;k<49;k++)
			{
				if(data[k]==i||data[k]==j) sum+=data[k-1]*data[k]-data[k-1];
				else sum+=data[k];
			}
			if(sum==2015)
				printf("%d %d\n",i-1,j-1);
		}
	return 0;
} 
